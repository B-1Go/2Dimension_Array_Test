#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <assert.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;

// let's make inventory! yeah~!!

// 뱀의 위치를 저장할 수 있는 자료형을 만들자
// list가 적당할 거 같다.

struct node
{
	int x;
	int y;
	node* next_node; // tail 방향
	node* prev_node; // head 방향

	node()
		: x(0)
		, y(0)
		, next_node(nullptr)
		, prev_node(nullptr)
	{}
	node(int _x, int _y, node* _next, node* _prev)
		: x(_x)
		, y(_y)
		, next_node(_next)
		, prev_node(_prev)
	{}
	~node()
	{}
};

class snake
{
private:
	int length;
	node* snake_head;
	node* snake_tail;

public:
	void push_front(int _x, int _y);
	void erase_tail();
	void snake_move(int _x, int _y);
	int get_length();
	
public:
	class iterator;
	iterator begin();
	
public:
	snake()
		: length(0)
		, snake_head(nullptr)
		, snake_tail(nullptr)
	{}
	~snake()
	{}

	class iterator
	{
	private:
		snake* iter_snake;
		node* iter_node;

	public:
		iterator()
			: iter_snake(nullptr)
			, iter_node(nullptr)
		{

		}
		iterator(snake* _snake, node* _node)
			: iter_snake(_snake)
			, iter_node(_node)
		{

		}
		~iterator()
		{

		}

	public:
		const node* operator*()
		{
			return iter_node;
		}

		iterator operator--() // head부터 시작해서 tail로 가니까 --로함
		{
			if (nullptr == iter_node)
			{
				assert("end iterator");
			}

			iter_node = iter_node->next_node;

			return *this;
		}
	};
};

void snake::push_front(int _x, int _y)
{
	node* temp = new node(_x, _y, nullptr, nullptr);

	if (snake_head == nullptr)
	{
		snake_head = temp;
		snake_tail = temp;
	}
	else
	{
		temp->next_node = snake_head;
		snake_head->prev_node = temp;
		snake_head = temp;
	}
	++length;
}

void snake::erase_tail()
{
	node* temp = snake_tail->prev_node;
	if (snake_tail == nullptr)
	{
		assert("snake_tail is nullptr");
	}
	else
	{
		snake_tail->prev_node->next_node = nullptr;
		delete(snake_tail);
		snake_tail = temp;
	}
}

void snake::snake_move(int _x, int _y)
{
	push_front(_x, _y);
	--length;
	erase_tail();
}

int snake::get_length()
{
	return length;
}

typename snake::iterator snake::begin()
{
	return iterator(this, snake_head);
}

int main()
{
	snake test;
	test.push_front(1, 1);
	test.push_front(2, 2);
	test.push_front(3, 3);
	test.push_front(4, 4);
	test.push_front(5, 5);
	test.push_front(10, 10);

	test.snake_move(20, 20);

	snake::iterator siter;
	siter = test.begin();

	for (int i = 0; i < test.get_length(); ++i)
	{
		cout << "x : " << (*siter)->x << ", y : " << (*siter)->y << endl;
		--siter;
	}

	return 0;
}