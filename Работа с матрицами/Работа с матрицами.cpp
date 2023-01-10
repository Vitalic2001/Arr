#include "iostream"

#include "fstream"

using namespace std;
int lenghtA = 0, lenghtB = 0, lenghtC = 0, lenghtN, sizeA, sizeB, sizeC;

char name2, name3;

int* A, * B, * C;

void menu() //функция для вывода меню

{

	setlocale(LC_ALL, "Russian");

	system("cls");

	cout << "1.Ввод матрицы A, B, C с клавиатуры " << "\n";

	cout << "2.Ввод матрицы из файла " << "\n";

	cout << "3.Вывести матрицу" << "\n";

	cout << "4.Редактировать элементы матрицы " << "\n";

	cout << "5.Задание 1" << "\n";

	cout << "6.Задание 9" << "\n";

	cout << "7.Выход из меню" << "\n" << "\n";

}
void lenght(int lenght) { //функция для ввода длины и ее проверки на натуральное число

	do {

		cout << "Введите размер матрицы : ";

		cin >> lenght;

		lenghtN = lenght;

		if (lenght <= 0)

		{

			cout << "Введите натеральное число \n";

		}

	} while (lenght <= 0);

}
void matrix(int* matrixName, int size) { //функция для ввода матрицы

	cout << "Введите элемент матрицы : ";

	for (int i = 0; i < size; i++) {

		cin >> matrixName[i];

	}

}
void vivod(int* matrixName, int size, int lenght) { //функция для вывода матрицы

	if (lenght > 0) {

		for (int i = 0; i < size; i++) {

			cout << matrixName[i] << " ";

			if ((i + 1) % lenght == 0) {

				cout << endl;

			}

		}

	}

	else {

		cout << "матрица не была введена " << endl;

	}

}
void vvodf() //Функция, осуществляющая импорт матриц из файла.

{
	ifstream inf("vvod.txt", ios_base::in);

	if (!inf.is_open())

	{

		cout << "Ошибка! Не удалось открыть файл для чтения." << endl;

		return;

	}

	inf >> lenghtA;

	sizeA = lenghtA * lenghtA;

	A = new int[sizeA];

	for (int i = 0; i < sizeA; i++)

	{

		inf >> A[i];

	}

	inf >> lenghtB;

	sizeB = lenghtB * lenghtB;

	B = new int[sizeB];

	for (int i = 0; i < sizeB; i++)

	{

		inf >> B[i];

	}

	inf >> lenghtC;

	sizeC = lenghtC * lenghtC;

	C = new int[sizeC];

	for (int i = 0; i < sizeC; i++)

	{

		inf >> C[i];

	}

	inf.close();

}
void vivodf(int* matrixName, int lenght, int size) { //файловый вывод

	ofstream out("vivod.txt");

	for (int i = 0; i < size; i++) {

		out << matrixName[i] << " ";

		if ((i + 1) % lenght == 0) {

			out << endl;

		}

	}

	cout << endl;

}
void vvod() { //функция для выполнения первого пункта меню

	char matrixName;

	do { //оператор для повторного ввода матрицы

		cout << "Введите имя матрицы :(A/B/C) ";

		cin >> matrixName;

		switch (matrixName) //оператор для выбора матрицы, которую хочешь ввести

		{

		case 'A':

			lenght(lenghtA);

			lenghtA = lenghtN;

			sizeA = lenghtA * lenghtA;

			A = new int[sizeA];

			matrix(A, sizeA);

			vivod(A, sizeA, lenghtA);

			break;

		case 'B':

			lenght(lenghtB);

			lenghtB = lenghtN;

			sizeB = lenghtN * lenghtN;

			B = new int[sizeB];

			matrix(B, sizeB);

			vivod(B, sizeB, lenghtB);

			break;

		case 'C':

			lenght(lenghtC);

			lenghtC = lenghtN;

			sizeC = lenghtN * lenghtN;

			C = new int[sizeA];

			matrix(C, sizeC);

			vivod(C, sizeC, lenghtC);

			break;

		default:

			cout << "Такой матрицы не существует" << endl;

		}

		cout << "Хотите ввести другую матрицу?(y/n): ";

		cin >> name2;

		if (name2 == 'n') {

			break;

		}

	} while (name2 == 'y');

}
int getSingleIndex(int row, int col, int numberOfCol) { //функция, которая предоставляет доступ к элементу сплющенного двумерного массива

	return (row * numberOfCol) + col;

}
void editm(int* matrixName, int lenght) { //функция для ввода элемента, который хочешь отредактировать

	int col, row, el;

	cout << "Введите строку и столбец: ";

	cin >> row;

	cin >> col;

	row--;

	col--;

	cout << "Введите новое значение элемента: ";

	cin >> el;

	if (row < lenght && col < lenght) { //проверка на существование выбранной строки и столбца в данной матрице

		matrixName[getSingleIndex(row, col, lenght)] = el;

	}

	else {

		cout << "Этот элемент не входит в матрицу" << endl;

	}

}
void matrixcheck(int* matrixName, int size, int lenght) { //проверка на существование матриц

	if (lenght > 0) {

		editm(matrixName, lenght);

		vivod(matrixName, size, lenght);

	}

	else {

		cout << "матрица не введена" << endl;

	}

}
void edit() { //функция для редактирования отдельного элемента матрицы

	char matrixName;

	do {

		cout << "Введите имя матрицы (A/B/C): ";

		cin >> matrixName;

		switch (matrixName) { //оператор для выбора матрицы, в которой будет отредактирован этот элемент

		case 'A':

			matrixcheck(A, sizeA, lenghtA);

			break;

		case 'B':

			matrixcheck(B, sizeB, lenghtB);

			break;

		case 'C':

			matrixcheck(C, sizeC, lenghtC);

			break;

		default:

			cout << "Такой матрицы не существует" << endl;

		}

		cout << "Хотите изменить другой элемент?(y/n): ";

		cin >> name2;

		if (name2 == 'n') {

			break;

		}

	} while (name2 == 'y');

}
void zadanie1() {

	int* bufM = new int[lenghtC]; //создание буферной матрицы по длине равной длине строки в матрице С

	int k = 0, n = 0, min;

	for (int i = 0; i < lenghtC; i++) {

		for (int j = 0; j < sizeA; j++) {

			if (C[i] == A[j]) { //цикл, проверяющий сколько раз элемнты первой строки матрицы С встречаются в матрице А

				n++;

			}

		}

		for (int j = 0; j < sizeB; j++) {

			if (C[i] == B[j]) { //цикл, проверяющий сколько раз элемнты первой строки матрицы С встречаются в матрице B

				n++;

			}

		}

	}

	min = n;

	n = 0;

	for (int i = lenghtC; i < sizeC; i++) { //цикл, проверяющий сколько раз элемнты остальных строк матрицы С встречаются в матрице А и B

		for (int j = 0; j < sizeA; j++) {

			if (C[i] == A[j]) {

				n++;

			}

		}

		for (int j = 0; j < sizeB; j++) {

			if (C[i] == B[j]) {

				n++;

			}

		}

		if ((i + 1) % lenghtC == 0) { //условие, проверяющее, дошел ли цикл до конца строки

			if (n < min) { //условие, для нахождения строки с минимальным количеством элементов, встречающихся в матрице А и В

				k = 0;

				for (int l = i - lenghtC + 1; l <= i; l++) { //запись строки с минимальным количеством элементов, встречающихся в матрице А и В в буферный массив

					bufM[k] = C[l];

					k++;

				}

				for (int l = i - lenghtC; l >= 0; l--) { //сдвигаем массив C вправо, чтобы освободить место для строки из буферного массива

					C[l + lenghtC] = C[l];

				}

				k = 0;

				for (int l = 0; l < lenghtC; l++) { //замена первой строки матрицы С на строку из буферного массива

					C[l] = bufM[k];

					k++;

				}

			}

			n = 0;

		}

	}

	cout << "Куда вывести результат задания?(с - в консоль, f- в файл): ";

	cin >> name3;

	ofstream out("vivod.txt");

	switch (name3) //опреатор для выбора файлового вывода или вывода в консоли результата задания

	{

	case 'f':

		out << "Результат выполнения задания: " << endl; //файловый вывод
		out << "Матрица A: " << endl; //файловый вывод

		for (int i = 0; i < sizeA; i++) {

			out << A[i] << " ";

			if ((i + 1) % lenghtA == 0) {

				out << endl;

			}

		}

		out << "Матрица B: " << endl; //файловый вывод

		for (int i = 0; i < sizeB; i++) {

			out << B[i] << " ";

			if ((i + 1) % lenghtB == 0) {

				out << endl;

			}

		}

		out << "Матрица C: " << endl; //файловый вывод

		for (int i = 0; i < sizeC; i++) {

			out << C[i] << " ";

			if ((i + 1) % lenghtC == 0) {

				out << endl;

			}

		}

		break;

	case 'c':

		vivod(A, sizeA, lenghtA); //вывод в консоль
		vivod(B, sizeB, lenghtB); //вывод в консоль
		vivod(C, sizeC, lenghtC); //вывод в консоль

		break;

	default:

		cout << "Введите 'f' или 'c'" << endl;

	}

	delete[]bufM;

}
void zadanie9() {


	if (sizeA == sizeB && sizeA == sizeC) { //проверка на возможность сложения матриц А и В и записи результата в буферную матрицу С
		int sumA = 0; //Счетчик для подсчета суммы столбца
		int sumB = 0; //Счетчик для подсчета суммы столбца
		int max; //матрица с максимальным значением элементов в столбце
		for (int k = 0; k < sizeC; k++) {
		for (int i = k; i < sizeA; i+= sqrt(sizeA)) { //цикл на поиск размера значения матрицы А
			sumA += A[i];
		}
		for (int i = k; i < sizeB; i+= sqrt(sizeA)) { //цикл на поиск размера значения матрицы А
			sumB += B[i];
		}

		if (sumA > sumB) {
			for (int i = k; i < sizeA; i+= sqrt(sizeA)) { //цикл на поиск размера значения матрицы А
				C[i] = A[i];
			}
		}
		else {
			for (int i = k; i < sizeB; i += sqrt(sizeA)) { //цикл на поиск размера значения матрицы А
				C[i] = B[i];
			}
		}
		sumA = 0;
		sumB = 0;
		}
		cout << "Куда вывести результат задания?(с - в консоль, f- в файл): ";

		cin >> name3;

		ofstream out("vivod.txt");

		switch (name3) //опреатор для выбора файлового вывода или вывода в консоли результата задания

		{

		case 'f':
			out << "Результат выполнения задания: " << endl; //файловый вывод

			for (int i = 0; i < sizeC; i++) {

				out << C[i] << " ";

				if ((i + 1) % lenghtC == 0) {

					out << endl;

				}

			}

			break;

		case 'c': //вывод в консоль

			for (int i = 0; i < sizeC; i++) {

				cout << C[i] << " ";

				if ((i + 1) % lenghtC == 0) {

					cout << endl;

				}

			}

			break;

		default:

			cout << "Введите 'f' или 'c'";

		}

	}

	else {

		cout << "Эти матрицы нельзя сложить " << endl;

	}


}

int main()

{

	int x;

	do {

		menu();

		cin >> x; //выбор пункта меню

		switch (x) {

		case 1:

			vvod();

			break;

		case 2:

			vvodf();

			break;

		case 3:

			cout << "Введите имя матрицы:(A/B/C) ";

			cin >> name3;

			switch (name3) {

			case 'A':

				cout << "Матрица A" << endl;

				vivod(A, sizeA, lenghtA);

				break;

			case 'B':

				cout << "Матрица B" << endl;

				vivod(B, sizeB, lenghtB);

				break;

			case 'C':

				cout << "Матрица C" << endl;

				vivod(C, sizeC, lenghtC);

				break;

			default: break;

			}

			break;

		case 4:

			edit();

			break;

		case 5:

			zadanie1();

			break;

		case 6:

			zadanie9();

			break;

		}

		if (x != 7) {

			system("pause");

		}

	} while (x != 7);

	return 0;

}
