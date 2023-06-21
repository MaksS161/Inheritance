#include <iostream>
#include<Windows.h>
using namespace std;

#define delimiter "\n-----------------------------------------------------------\n"

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		dlue = 0x00FF0000,
		yellow = 0x0000FFFF,
		grey = 0x00AAAAAA,
		white = 0x00FFFFFF,
	};
	enum Limits
	{
		MIN_START_X = 10,
		MAX_START_X = 1000,
		MIN_START_Y = 10,
		MAX_START_Y = 800,
		MIN_LINE_WIDTH = 3,
		MAX_LINE_WIDTH = 30,
		//-------------------
		MIN_LENGHT = 20,
		MAX_LENGHT = 200,

	};

#define SHAPE_TAKE_PARAMETRS Color color, int start_x, int start_y, int line_width =5
#define SHAPE_GIVE_PARAMETRS  color, start_x,  start_y, line_width

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;

	public:
		Shape(SHAPE_TAKE_PARAMETRS)
		{
			set_color(color);
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		Color get_color()const
		{
			return color;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		void set_start_x(int start_x)
		{
			if (start_x < Limits::MIN_START_X)start_x = Limits::MIN_START_X;
			if (start_x > Limits::MAX_START_X)start_x = Limits::MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Limits::MIN_START_Y)start_y = Limits::MIN_START_Y;
			if (start_y > Limits::MAX_START_Y)start_y = Limits::MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < Limits::MIN_LINE_WIDTH)line_width = Limits::MIN_LINE_WIDTH;
			if (line_width > Limits::MAX_LINE_WIDTH)line_width = Limits::MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

		virtual double get_area()const = 0;
		virtual double get_perimetr()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры = " << get_area() << endl;
			cout << "Периметр фигуры = " << get_perimetr() << endl;
			draw();
		}
	};


	class Rectangle :public Shape
	{
		double length;	//длина
		double width;	//ширина
	public:
		Rectangle(double width, double length, SHAPE_TAKE_PARAMETRS) :Shape(SHAPE_GIVE_PARAMETRS)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}
		void set_width(double width)
		{
			if (width < MIN_LENGHT)width = MIN_LENGHT;
			if (width > MAX_LENGHT)width = MAX_LENGHT;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < MIN_LENGHT)length = MIN_LENGHT;
			if (length > MAX_LENGHT)length = MAX_LENGHT;
			this->length = length;
		}
		double get_length()const
		{
			return length;
		}
		double get_width()const
		{
			return width;
		}
		double get_diagonal()const
		{
			//return side * sqrt(2);
			return sqrt(width * width + length * length);
		}
		double get_area()const
		{
			return length * width;
		}
		double get_perimetr()const
		{
			return (length + width) * 2;
		}
		void draw()const
		{
			//Для рисования используется девайс:
			//WinGDI - Windows Graphics Device InterfaceWi

			//1. Получаем обработчик окна консоли:
			HWND hwnd = GetConsoleWindow();

			//2. Получаем контекст устройства для окна консоли:
			HDC hdc = GetDC(hwnd); //Контекст устройство - это то, на чем мы будем рисовать 
			// Теперь нужно определиться с тем, чем мы будем рисовать 

			//3. Создаем карандаш: Карандаш рисует контур фигуры 
			HPEN hPen = CreatePen(PS_SOLID, 5, color);	//PS_SOLID - сплошная линия 
			// 5 - толщина линии
//4. Создаем кисть. Кисть выполняет заливку фигуры 
			HBRUSH hBrush = CreateSolidBrush(color);

			//5. Перед рисование нужно выбрать чем, и на чем мы будем рисовать 

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6. Когда все объекты созданы и выбраны, можно рисовать нужную нам фигуру,
			// при помощи соответствующей нам функции
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);//В скобках 2-5 координаты 

			//7. Кисть и карандаш так же занимают ресурсы поэтому их тоже нужно удалить:

			DeleteObject(hPen);
			DeleteObject(hBrush);


			//8. Освобождаем контекст устройства:
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника = " << get_width() << endl;
			cout << "Длина прямоугольника = " << get_length() << endl;
			cout << "Диагональ прямоугольника = " << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETRS) :Rectangle(side, side, SHAPE_GIVE_PARAMETRS) {}
		~Square() {}
	};

}

void main()
{
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord= {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
	*/
	setlocale(LC_ALL, "");

	Geometry::Square square(100, Geometry::Color::red, 400, 10, 5);
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rect(200, 100, Geometry::Color::grey, 400, 160, 5);
	rect.info();
	cout << delimiter << endl;
}
