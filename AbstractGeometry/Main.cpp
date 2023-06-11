#include <iostream>
#include<Windows.h>
using namespace std;

#define delimiter "\n---------------------------------------------\n"
namespace Geometry
{
	class Shape
	{
	public:
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

	class Sguare :public Shape
	{
		double side;
	public:
		Sguare(double side)
		{
			this->side = side;
		}
		~Sguare() {}
		double get_side()const
		{
			return side;
		}
		double get_diagonal()const
		{
			return side * sqrt(2);
			//return sqrt(side*side * 2); 
		}
		double get_area()const
		{
			return side * side;
		}

		double get_perimetr()const
		{
			return side * 4;
		}
		void draw()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата = " << get_side() << endl;
			cout << "Диагональ квадрата = " << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double length;	//длина
		double width;	//ширина
	public:
		Rectangle(double length, double width)
		{
			this->width = width;
			this->length = length;
		}
		~Rectangle() {}
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
			return sqrt(width* width+length* length);
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
			//Для рисования используется дивайс:
			//WinGDI - Windows Grapics Device InterfaceWi

			//1. Получем обрабодчик окна консоли:
			HWND hwnd = GetConsoleWindow();

			//2. Получаем контекст устройства для окна консоли:
			HDC hdc = GetDC(hwnd); //Контекст устройство - это то, на чем мы будем рисовать 
			// Теперь нужно определиться с тем, чем мы будем рисовать 
			
			//3. Создаем карандаш: Карандаш рисует контур фигуры 
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));	//PS_SOLID - сплошная линия 
																// 5 - толщина линии
			//4. Создаем кисть. Кисть выполняет заливку фигуры 
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			//5. Перед рисование нужно выбрать чем, и на чем мы будем рисовать 

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6. Когда все объекты созданы и выбраны, можно рисовать нужную нам фигуру,
			// при помощи соответствующей нам функции
			::Rectangle(hdc, 100, 100, 300, 200);//В скобках 2-5 координаты 

			//7. Кисть и карандаш так же занимают ресурсы поэтому их тоже нужно удолить:

			DeleteObject(hPen);
			DeleteObject(hBrush);


			//8. Освобождаем контекст устройства:
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника = " << get_width()<<endl;
			cout << "Длина прямоугольника = " << get_length() << endl;
			cout << "Диагональ прямоугольника = "<<get_diagonal()<<endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");

	Geometry::Sguare square(5);
	cout << "Длина стороны квадрата = " << square.get_side() << endl;
	cout << "Диагональ квадрата = " << square.get_diagonal() << endl;
	cout << "Площадь квадрата = " << square.get_area() << endl;
	cout << "Периметр квадрата = " << square.get_perimetr() << endl;
	square.draw();
	cout << delimiter << endl;
	square.info();

	cout << delimiter << endl;
	Geometry:: Rectangle rect(25, 15);
	rect.info();
}

