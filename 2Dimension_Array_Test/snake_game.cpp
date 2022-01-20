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
// 과일 생성 및 먹기 기능
// 과일 먹으면 꼬리 생기기 기능
// 꼬리 생기게 자료구조 변경
// 점수 기능

struct node
{
	int x;
	int y;
	node* next_node; // head -> tail 방향
	node* prev_node; // head -> tail 방향

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

		bool operator==(const iterator& _otheriter)
		{
			if (this->iter_snake == _otheriter.iter_snake && this->iter_node == _otheriter.iter_node)
			{
				return true;
			}
			return false;
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

enum class Diraction
{
	ESC = 27,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

// snake 만들기
snake snake_body;
snake::iterator snake_iter;
snake::iterator snake_head;
// 깜빡이 차단용 입력 전용
bool isinput, gamestop;
// 포지션 저장 및 방향, 음식 위치 및 점수
int x = 0, y = 0, dir = 0, fx, fy, score;
int board_size = 20;
// 2차원 문자열 배열 동적 할당
string** s_matrix = new string * [board_size];

void food_reset()
{
	fx = rand() % board_size;
	fy = rand() % board_size;
}

void setup()
{
	for (int i = 0; i < board_size; ++i)
	{
		s_matrix[i] = new string[board_size];
	}
	gamestop = true;
	snake_body.push_front(x, y);
	food_reset();
}

void setup_clear()
{
	// 2차원 배열 동적 할당 해제
	for (int i = 0; i < board_size; ++i)
	{
		delete[] s_matrix[i];
	}
	delete[] s_matrix;
}

void draw()
{
	system("cls");
	// inventory 창
	for (int i = 0; i < board_size; ++i)
	{
		for (int j = 0; j < board_size; ++j)
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
	for (int i = 0; i < board_size; ++i)
	{
		for (int j = 0; j < board_size; ++j)
		{
			s_matrix[i][j] = "□";
		}
	}
	s_matrix[fx][fy] = "★";
	snake_iter = snake_body.begin();
	snake_head = snake_body.begin();
	s_matrix[(*snake_iter)->x][(*snake_iter)->y] = "◆";
	--snake_iter;
	for (int i = 0; i < snake_body.get_length() - 1; ++i)
	{
		if ((*snake_head)->x == (*snake_iter)->x && (*snake_head)->y == (*snake_iter)->y)
		{
			gamestop = false;
		}
		s_matrix[(*snake_iter)->x][(*snake_iter)->y] = "■";
		--snake_iter;
	}
}

void logic()
{
	switch (dir)
	{
	case (int)Diraction::UP:
		if (x <= 0){ x = x + (board_size - 1); }
		else { x--; }
		break;
	case (int)Diraction::LEFT:
		if (y <= 0) { y = y + (board_size - 1); }
		else { y--; }
		break;
	case (int)Diraction::RIGHT:
		if (y >= board_size - 1) { y = y - (board_size - 1); }
		else { y++; }
		break;
	case (int)Diraction::DOWN:
		if (x >= board_size - 1) { x = x - (board_size - 1); }
		else { x++; }
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
		//	input(); // 입력 1번에 1칸 움직이게 하기
		//}
		input();
		logic();
		Sleep(50);
	}

	setup_clear();
	return 0;
}