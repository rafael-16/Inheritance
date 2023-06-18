#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>

using namespace std;

#define delimiter "\n--------------------\n"

namespace Geometry
{
	enum Color			// enum (энамурейшен, перечисление) - это набор целочисленных констант
	{
		grey = 0x00808080,
		red = 0x000000FF,
		yellow = 0x0000FFFF,
		lime = 0x0000FF00,
		green = 0x00008000,
		aqua = 0x00FFFF00,
		blue = 0x00FF0000,
		white = 0x00FFFFFF
	};
	enum Limits
	{
		MIN_START_X = 50,
		MAX_START_X = 1000,
		MIN_START_Y = 50,
		MAX_START_Y = 800,
		MIN_LINE_WIDTH = 3,
		MAX_LINE_WIDTH = 30,
		MIN_LENGTH = 20,
		MAX_LENGTH = 800
	};

#define SHAPE_TAKE_PARAMETERS Color color, int start_x, int start_y, int line_width=3
#define SHAPE_GIVE_PARAMETERS color, start_x, start_y, line_width

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;
	public:
		Shape(SHAPE_TAKE_PARAMETERS)
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
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double length;
		double width;
	public:
		Rectangle(double width, double length, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_length(length);
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
			return sqrt(length * length + width * width);
		}
		double get_area()const
		{
			return length * width;
		}
		double get_perimeter()const
		{
			return 2 * (length + width);
		}

		void set_width(double width)
		{
			if (width < MIN_LENGTH)width = MIN_LENGTH;
			if (width > MAX_LENGTH)width = MAX_LENGTH;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < MIN_LENGTH)length = MIN_LENGTH;
			if (length > MAX_LENGTH)length = MAX_LENGTH;
			this->length = length;
		}

		void draw()const
		{
			//1. Получаем обработчик окна консоли
			HWND hwnd = GetConsoleWindow();

			//2. Получаем контекст устройства для окна консоли (контекст устройства это то на чем будем рисовать)
			HDC hdc = GetDC(hwnd);


			//Теперь надо определиться с тем чем мы будем рисовать
			//3. Создаем карандаш, карандаш рисует фигуры
			HPEN hPen = CreatePen(PS_SOLID, line_width, RGB(255, 255, 255)); // PS_SOLID - сплошная линия, 3 - толщина линии


			//4. Создаем кисть. Кисть выполняет заливку фигуры
			HBRUSH hBrush = CreateSolidBrush(color);


			//5. Перед рисованием нужно выбрать чем и на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);


			//6. Когда все объекты созданы и выбраны, можно рисовать фигуры при помощи соответсвующей функции
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);


			//7. Кисть и карандаш занимают ресурсы, поэтому нужно удалить эти объекты после использования
			DeleteObject(hPen);
			DeleteObject(hBrush);


			//8. Освобождаем контекст устройства
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\t" << color << endl;
			cout << "Длина:\t\t" << get_length() << endl;
			cout << "Ширина:\t\t" << get_width() << endl;
			cout << "Диагональ:\t" << get_diagonal() << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		void set_radius(double radius)
		{
			if (radius < Limits::MIN_LENGTH)radius = Limits::MIN_LENGTH;
			if (radius > Limits::MAX_LENGTH)radius = Limits::MAX_LENGTH;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		double get_area()const
		{
			return M_PI * radius * radius;
		}
		double get_perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();//	обработчик окна консоли
			HDC hdc = GetDC(hwnd);//			контекст устройства

			HPEN hPen = CreatePen(PS_SOLID, line_width, RGB(255, 255, 255));//	контур фигуры
			HBRUSH hBrush = CreateSolidBrush(color);//	заливка фигуры

			SelectObject(hdc, hPen);//		выбираем объект контура(карандаш)
			SelectObject(hdc, hBrush);//	выбираем объект заливки(кисть)

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hPen);//	удаляем объект
			DeleteObject(hBrush);//	удаляем объект

			ReleaseDC(hwnd, hdc);//	освобождаем контекст устройства
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\t" << color << endl;
			cout << "Радиус:\t\t" << radius << endl;
			Shape::info();
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {};
		~Triangle() {}
		virtual double get_height()const = 0;
		void info()const
		{
			cout << "Высота:\t\t" << get_height() << endl;
			Shape::info();
		}
	};
	class EquillateralTriangle :public Triangle
	{
		double side;
	public:
		EquillateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquillateralTriangle() {}
		void set_side(double side)
		{
			if (side < Limits::MIN_LENGTH)side = Limits::MIN_LENGTH;
			if (side > Limits::MAX_LENGTH)side = Limits::MAX_LENGTH;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return side * sqrt(3) / 2;
		}
		double get_area()const
		{
			return side * side * sqrt(3) / 4;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, RGB(255, 255, 255));
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertex[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};
			::Polygon(hdc, vertex, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\t" << color << endl;
			cout << "Сторона:\t" << get_side() << endl;
			Triangle::info();
		}
	};

	class IsoscelesTriangle :public Triangle
	{
		double base;
		double side;
	public:
		IsoscelesTriangle(double base, double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_base(base);
			set_side(side);
		}
		~IsoscelesTriangle() {}
		void set_base(double base)
		{
			if (base < Limits::MIN_LENGTH)base = Limits::MIN_LENGTH;
			if (base > Limits::MAX_LENGTH)base = Limits::MAX_LENGTH;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < Limits::MIN_LENGTH)side = Limits::MIN_LENGTH;
			if (side > Limits::MAX_LENGTH)side = Limits::MAX_LENGTH;
			this->side = side;
		}
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return side * 2 + base;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, RGB(255, 255, 255));
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertex[] =
			{
				{start_x, start_y + side},
				{start_x + base, start_y + side},
				{start_x + base / 2, start_y + side - get_height()}
			};
			::Polygon(hdc, vertex, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Цвет:\t\t" << color << endl;
			cout << "Основание:\t" << get_base() << endl;
			cout << "Сторона:\t" << get_side() << endl;
			Triangle::info();
		}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// Получаем окно консоли
	//COORD coord = {};// Объявляем экземпляр структуры COORD. Мы никак не используем его, но без него нельзя вызвать следущую функцию, если не NULL
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, NULL); // Функция SetConsoleDisplayMode задает режим отображения консоля

	setlocale(LC_ALL, "");
	Geometry::Square square(50, Geometry::Color::red, 300, 100, 5);
	square.info();
	cout << "\n";
	Geometry::Rectangle rect(250, 150, Geometry::Color::grey, 400, 100);
	rect.info();
	cout << "\n";
	Geometry::Circle sun(150, Geometry::Color::yellow, 700, 50, 7);
	sun.info();
	cout << "\n";
	Geometry::EquillateralTriangle eq_tri(200, Geometry::Color::green, 400, 300, 5);
	eq_tri.info();
	cout << "\n";
	Geometry::IsoscelesTriangle iso_tri(220, 140, Geometry::Color::blue, 700, 360, 15);
	iso_tri.info();
}