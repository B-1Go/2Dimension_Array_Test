#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <assert.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;

// let's make snake game!!

// todo
// ���� ���� �� �Ա� ���
// ���� ������ ���� ����� ���
// ���� ����� �ڷᱸ�� ����
// ���� ���

struct node
{
	int x;
	int y;
	node* next_node; // head -> tail ����
	node* prev_node; // head -> tail ����

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

		iterator operator--() // head���� �����ؼ� tail�� ���ϱ� --����
		{
			if (nullptr == iter_node)
			{
				assert("end iterator");
			}

			iter_node = iter_node->next_node;

			return *this;
		}

		//iterator operator==()
		//{
		//	// �� �Լ� �����!
		//}
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

enum class Diraction
{
	ESC = 27,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

// snake �����
snake snake_body;
snake::iterator snake_iter;
snake::iterator snake_head;
// ������ ���ܿ� �Է� ����
bool isinput, gamestop;
// ������ ���� �� ����, ���� ��ġ �� ����
int x = 0, y = 0, dir = 0, fx, fy, score;
int inven_size = 20;
// 2���� ���ڿ� �迭 ���� �Ҵ�
string** s_matrix = new string * [inven_size];

void food_reset()
{
	fx = rand() % inven_size;
	fy = rand() % inven_size;
}

void setup()
{
	for (int i = 0; i < inven_size; ++i)
	{
		s_matrix[i] = new string[inven_size];
	}
	gamestop = true;
	snake_body.push_front(x, y);
	food_reset();
}

void setup_clear()
{
	// 2���� �迭 ���� �Ҵ� ����
	for (int i = 0; i < inven_size; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;
}

void draw()
{
	system("cls");
	// inventory â
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			cout << s_matrix[i][j];
		}
		cout << endl;
	}
	isinput = true;
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "score : " << score << endl;
	cout << "x : " << x << ", y : " << y << endl;
	cout << "fx : " << fx << ", fy : " << fy << endl;
}

void input()
{
	if (_kbhit())
	{
		char c = _getch();
		if (c == -32)
		{
			c = _getch();

			switch (c)
			{
			case (int)Diraction::UP:
				dir = (int)Diraction::UP;
				break;
			case (int)Diraction::LEFT:
				dir = (int)Diraction::LEFT;
				break;
			case (int)Diraction::RIGHT:
				dir = (int)Diraction::RIGHT;
				break;
			case (int)Diraction::DOWN:
				dir = (int)Diraction::DOWN;
				break;
			default:
				dir = 0;
				break;
			}
		}
		else if (c == (int)Diraction::ESC)
		{
			dir = (int)Diraction::ESC;
		}
		isinput = false;
	}
}

void update()
{
	for (int i = 0; i < inven_size; ++i)
	{
		for (int j = 0; j < inven_size; ++j)
		{
			s_matrix[i][j] = "��";
		}
	}
	s_matrix[fx][fy] = "��";
	snake_iter = snake_body.begin();
	s_matrix[(*snake_iter)->x][(*snake_iter)->y] = "��";
	--snake_iter;
	for (int i = 0; i < snake_body.get_length() - 1; ++i)
	{
		if (snake_head == snake_iter)
		{

		}
		s_matrix[(*snake_iter)->x][(*snake_iter)->y] = "��";
		--snake_iter;
	}
}

void logic()
{
	switch (dir)
	{
	case (int)Diraction::UP:
		if (x <= 0) { x = x + (inven_size - 1); }
		else { x--; }
		//dir = 0;
		break;
	case (int)Diraction::LEFT:
		if (y <= 0) { y = y + (inven_size - 1); }
		else { y--; }
		//dir = 0;
		break;
	case (int)Diraction::RIGHT:
		if (y >= inven_size - 1) { y = y - (inven_size - 1); }
		else { y++; }
		//dir = 0;
		break;
	case (int)Diraction::DOWN:
		if (x >= inven_size - 1) { x = x - (inven_size - 1); }
		else { x++; }
		//dir = 0;
		break;
	case (int)Diraction::ESC:
		gamestop = false;
		break;
	default:
		dir = 0;
		break;
	}
	if (x == fx && y == fy)
	{
		snake_body.push_front(x, y);
		++score;
		food_reset();
	}
	else
	{
		snake_body.snake_move(x, y);
	}
}

int main()
{
	setup();

	while (gamestop)
	{
		update();
		draw();
		//while (isinput)
		//{
		//	input();
		//}
		input();
		logic();
		Sleep(100);
	}

	setup_clear();
	return 0;
}