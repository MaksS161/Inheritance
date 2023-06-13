#include <iostream>
#include<Windows.h>
using namespace std;

#define delimiter "\n-----------------------------------------------------------\n"
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
			/*for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/ //Звездочки
			
			HWND hwnd = GetConsoleWindow();// получаем обрабодчик
			HDC hdc = GetDC(hwnd); //Контекст устройства
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));//Создаем карандаш
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));// Создаем кисть
			SelectObject(hdc, hPen);//Выбираем чем и на чем 
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, 400, 0, 500, 100);//Выбираем функцию рисования
			DeleteObject(hPen);// Удаляем кисть и карандаш
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);//Освобождаем контекст устройства
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
			//Для рисования используется девайс:
			//WinGDI - Windows Graphics Device InterfaceWi

			//1. Получаем обработчик окна консоли:
			HWND hwnd = GetConsoleWindow();

			//2. Получаем контекст устройства для окна консоли:
			HDC hdc = GetDC(hwnd); //Контекст устройство - это то, на чем мы будем рисовать 
			// Теперь нужно определиться с тем, чем мы будем рисовать 
			
			//3. Создаем карандаш: Карандаш рисует контур фигуры 
			HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));	//PS_SOLID - сплошная линия 
																// 5 - толщина линии
			//4. Создаем кисть. Кисть выполняет заливку фигуры 
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));

			//5. Перед рисование нужно выбрать чем, и на чем мы будем рисовать 

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//6. Когда все объекты созданы и выбраны, можно рисовать нужную нам фигуру,
			// при помощи соответствующей нам функции
			::Rectangle(hdc, 400, 150, 600, 250);//В скобках 2-5 координаты 

			//7. Кисть и карандаш так же занимают ресурсы поэтому их тоже нужно удалить:

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

class Triangle :public Shape
{
	double a; //Сторона треульника А
	double b; //Сторона треульника B
	double c; //Сторона треульника C
public:
	Triangle(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	~Triangle() {}

	double get_a()const
	{
		return a;
	}
	double get_b()const
	{
		return b;
	}
	double get_c()const
	{
		return c;
	}
	double get_area()const
	{
		double p = (a + b + c) / 2;//полупериметр
		return sqrt(p * (p - a) * (p - b) * (p - c));//формула Герона
	}
	double get_perimetr()const
	{
		return a + b + c;
	}
	void draw()const
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
		HBRUSH hBrush = CreateSolidBrush(RGB(225, 0, 0));
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		POINT points[]={{400, 400 }, {450, 300 }, {500, 400 }};
		:: Polygon(hdc, points, 3);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
	}

	void info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "1 сторона треугольника = " << a << endl;
		cout << "2 сторона треугольника = " << b << endl;
		cout << "3 сторона треугольника = " << c << endl;
		Shape::info();
	}
};
class Circle :public Shape
{
	double radius;
public:
	Circle(double radius)
	{
		this->radius = radius;
	}
	~Circle(){}
	double get_radius()const
	{
		return radius;
	}
	double get_diameter()const
	{
		return radius * 2;
	}
	double get_area()const
	{
		return radius*radius* 3.14;
	}
	double get_perimetr()const
	{
		return radius*2*3.14;
	}
	void draw()const
	{
		HWND hwnd = GetConsoleWindow();// Получаем обрабодчик
		HDC hdc = GetDC(hwnd); //Контекст устройства
		HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));//Создаем карандаш
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));// Создаем кисть
		SelectObject(hdc, hPen);//Выбираем чем и на чем 
		SelectObject(hdc, hBrush);
		::Ellipse(hdc, 400, 460, 500, 560);//Выбираем функцию рисования
		DeleteObject(hPen);// Удаляем кисть и карандаш
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);//Освобождаем контекст устройства
	}
	void info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "Радиус круга =" << get_radius() << endl;
		cout << "Диаметр круга =" << get_diameter() << endl;
		Shape::info();
	}
};
}

void main()
{
	setlocale(LC_ALL, "");

	Geometry::Sguare square(5);
	/*cout << "Длина стороны квадрата = " << square.get_side() << endl;
	cout << "Диагональ квадрата = " << square.get_diagonal() << endl;
	cout << "Площадь квадрата = " << square.get_area() << endl;
	cout << "Периметр квадрата = " << square.get_perimetr() << endl;
	square.draw();
	cout << delimiter << endl;*/
	square.info();

	cout << delimiter << endl;
	Geometry:: Rectangle rect(25, 15);
	rect.info();
	
	cout << delimiter << endl;
	Geometry::Triangle tria(15,15,20);
	tria.info();

	cout << delimiter << endl;
	Geometry::Circle circ(15);
	circ.info();
}

