#include<Windows.h>
#include<iostream>

using namespace std;

#define delimiter "\n-------------------------------\n"

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
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimetr() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side)
		{
			this->side = side;
		}
		~Square() {}
		double get_side()const
		{
			return side;
		}
		double get_diagonal()const
		{
			return side * sqrt(2);
		}
		double get_area()const
		{
			return side * side;
		}
		double get_perimetr()const
		{
			return 4 * side;
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
			cout << "Длина стороны:\t" << get_side() << endl;
			cout << "Диагональ:\t" << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double lenght;
		double width;
		double x_st = 600, y_st = 200;
		double x_end = 800, y_end = 300;
	public:
		Rectangle(double lenght, double width)
		{
			this->lenght = lenght;
			this->width = width;
		}
		~Rectangle() {}
		double get_lenght()const
		{
			return lenght;
		}
		double get_width()const
		{
			return width;
		}
		double get_diagonal()const
		{
			return sqrt(lenght * lenght + width * width);
		}
		double get_area()const
		{
			return lenght * width;
		}
		double get_perimetr()const
		{
			return 2 * (lenght + width);
		}
		void draw()const
		{
			//1. Получаем обработчик окна консоли
			HWND hwnd = GetConsoleWindow();

			//2. Получаем контекст устройства для окна консоли (контекст устройства это то на чем будем рисовать)
			HDC hdc = GetDC(hwnd);
			//Теперь надо определиться с тем чем мы будем рисовать
			//3. Создаем карандаш, карандаш рисует фигуры
			HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255)); // PS_SOLID - сплошная линия, 5 - толщина линии
			//4. Создаем кисть. Кисть выполняет заливку фигуры
			HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
			//5. Перед рисованием нужно выбрать чем и на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6. Когда все объекты созданы и выбраны, можно рисовать фигуры при помощи соответсвующей функции
			::Rectangle(hdc, x_st, y_st, x_end, y_end);
			//7. Кисть и карандаш занимают ресурсы, поэтому нужно удалить эти объекты после использования
			DeleteObject(hPen);
			DeleteObject(hBrush);
			//8.  Освобождаем контекст устройства
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\tКрасный" << endl;
			cout << "Начальная точка:" << "(" << x_st << ", " << y_st << ")" << endl;
			cout << "Конечная точка:\t" << "(" << x_end << ", " << y_end << ")" << endl;
			cout << "Длина:\t\t" << get_lenght() << endl;
			cout << "Ширина:\t\t" << get_width() << endl;
			cout << "Диагональ:\t" << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Circle :public Shape
	{
		const double pi = 3.14;
		double radius;
	public:
		Circle(double radius)
		{
			this->radius = radius;
		}
		~Circle() {}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const
		{
			return pi * radius * radius;
		}
		double get_perimetr()const
		{
			return 2 * pi * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();//  Обработчик окна
			HDC hdc = GetDC(hwnd);// Контекст устройства
			HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));// Контур фигуры (карандаш)
			HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));// Заливка (Кисть)
			// Выбираем с чем на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Ellipse(hdc, 500, 500, 600, 600);
			//  Удаляем выбранные объекты кисти и карандаша
			DeleteObject(hPen);
			DeleteObject(hBrush);
			// Освобождаем контекст устройства
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\tЗеленый" << endl;
			cout << "Радиус:\t\t" << radius << endl;
			cout << "Диаметр:\t" << radius * 2 << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
		double a, b, c;
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
			double p_perimetr = (a + b + c) / 2;
			return sqrt(p_perimetr * (p_perimetr - a) * (p_perimetr - b) * (p_perimetr - c));
		}
		double get_perimetr()const
		{
			return a + b + c;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();//  Обработчик окна
			HDC hdc = GetDC(hwnd);// Контекст устройства
			HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));// Контур фигуры (карандаш)
			//HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));// Заливка (Кисть)
			// Выбираем с чем на чем рисовать
			SelectObject(hdc, hPen);
			//SelectObject(hdc, hBrush);

			::MoveToEx(hdc, 300, 500, NULL);
			::LineTo(hdc, 250, 250);
			::LineTo(hdc, 550, 450);
			::LineTo(hdc, 300, 500);

			DeleteObject(hPen);
			//DeleteObject(hBrush);
			// Освобождаем контекст устройства
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона \"a\":\t" << a << endl;
			cout << "Сторона \"b\":\t" << b << endl;
			cout << "Сторона \"c\":\t" << c << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5);
	//cout << "Длина стороны квадрата:\t" << square.get_side() << endl;
	//cout << "Диагональ квадрата:\t" << square.get_diagonal() << endl;
	//cout << "Площадь квадрата:\t" << square.get_area() << endl;
	//cout << "Периметр квадрата:\t" << square.get_perimetr() << endl;
	//square.draw();
	//cout << delimiter << endl;
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rect(25, 15);
	rect.info();
	cout << delimiter << endl;
	Geometry::Circle circle(15);
	circle.info();
	cout << delimiter << endl;
	Geometry::Triangle triangle(15, 12, 18);
	triangle.info();
}