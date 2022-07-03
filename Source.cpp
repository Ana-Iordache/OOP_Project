#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//CLASA 1
class Column
{
private:
	char* name; // numele coloanei
	char* type; // tipul de data al coloanei (number, varcha2, char etc.)
	string* constraints; // array de restrictii (string de mai multe stringuri)
	int nbOfConstraints; // numarul de restrictii
	int nbOfNullValues; // numarul de valori "null" existente intr-o coloana

public:
	Column()
	{
		name = nullptr;
		type = nullptr;
		constraints = nullptr;
		nbOfConstraints = 0;
		nbOfNullValues = 0;
	}
	//constructor 1 cu parametri
	Column(const char* name, const char* type, string* constraints, int nbOfConstraints, int nbOfNullValues)
	{
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		else
		{
			this->name = nullptr;
		}

		if (type != nullptr)
		{
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);
		}
		else
		{
			this->type = nullptr;
		}

		if (constraints != nullptr && nbOfConstraints > 0)
		{
			this->nbOfConstraints = nbOfConstraints;
			this->constraints = new string[nbOfConstraints];
			for (int i = 0; i < nbOfConstraints; i++)
			{
				this->constraints[i] = constraints[i];
			}
		}
		else
		{
			this->constraints = nullptr;
			this->nbOfConstraints = 0;
		}

		this->nbOfNullValues = nbOfNullValues;
	}

	//constructor 2 cu parametri
	Column(const char* name, const char* type) :Column()
	{
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
		else
		{
			this->name = nullptr;
		}

		if (type != nullptr)
		{
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);
		}
		else
		{
			this->type = nullptr;
		}
	}

	//constructor de copiere
	Column(const Column& c)
	{
		if (c.name != nullptr)
		{
			this->name = new char[strlen(c.name) + 1];
			strcpy_s(this->name, strlen(c.name) + 1, c.name);
		}
		else
		{
			this->name = nullptr;
		}

		if (c.type != nullptr)
		{
			this->type = new char[strlen(c.type) + 1];
			strcpy_s(this->type, strlen(c.type) + 1, c.type);
		}
		else
		{
			this->type = nullptr;
		}

		if (c.constraints != nullptr && c.nbOfConstraints > 0)
		{
			this->nbOfConstraints = c.nbOfConstraints;
			this->constraints = new string[c.nbOfConstraints];
			for (int i = 0; i < c.nbOfConstraints; i++)
			{
				this->constraints[i] = c.constraints[i];
			}
		}
		else
		{
			this->constraints = nullptr;
			this->nbOfConstraints = 0;
		}
		this->nbOfNullValues = c.nbOfNullValues;
	}

	//destructor
	~Column()
	{
		if (name != nullptr) {
			delete[] name;
		}

		if (type != nullptr) {
			delete[] type;
		}

		if (constraints != nullptr)
		{
			delete[] constraints;
		}
	}

	//supraincarcare operator=
	Column& operator=(const Column& c)
	{
		if (name != nullptr)
		{
			delete[] name;
		}

		if (type != nullptr)
		{
			delete[] type;
		}

		if (constraints != nullptr)
		{
			delete[] constraints;
		}

		if (c.name != nullptr)
		{
			this->name = new char[strlen(c.name) + 1];
			strcpy_s(this->name, strlen(c.name) + 1, c.name);
		}
		else
		{
			this->name = nullptr;
		}

		if (c.type != nullptr)
		{
			this->type = new char[strlen(c.type) + 1];
			strcpy_s(this->type, strlen(c.type) + 1, c.type);
		}
		else
		{
			this->type = nullptr;
		}

		if (c.constraints != nullptr && c.nbOfConstraints > 0)
		{
			this->nbOfConstraints = c.nbOfConstraints;
			this->constraints = new string[c.nbOfConstraints];
			for (int i = 0; i < c.nbOfConstraints; i++)
			{
				this->constraints[i] = c.constraints[i];
			}
		}
		else
		{
			this->constraints = nullptr;
			this->nbOfConstraints = 0;
		}
		this->nbOfNullValues = c.nbOfNullValues;
		return *this;
	}

	//supraincarcare operator[]
	string& operator[](int index)
	{
		if (index >= 0 && index < nbOfConstraints)
		{
			return constraints[index];
		}
		throw exception("index invalid");
	}

	//supraincarcare operator-- preincrementare
	Column operator--()
	{
		this->nbOfNullValues--;
		return *this;
	}

	//supraincarcare operator-- postincrementare
	Column operator--(int i)
	{
		Column copy = *this;
		this->nbOfNullValues--;
		return copy;
	}

	//supraincarcare operator cast
	operator int()
	{
		return nbOfNullValues;
	}

	//supraincarcare operator!
	bool operator!()
	{
		return nbOfConstraints > 0;
	}

	//supraincrcare operator<
	bool operator <(const Column& c)
	{
		if (nbOfConstraints < c.nbOfConstraints)
		{
			return true;
		}
		return false;
	}

	//apel operator==
	bool operator==(const Column& c)
	{
		if (strcmp(type, c.type) == 0)
		{
			return true;
		}
		return false;
	}

	char* getName()
	{
		return name;
	}
	void setName(const char* name)
	{
		if (name != nullptr)
		{
			if (this->name != nullptr)
			{
				delete[] this->name;
			}
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}

	char* getType()
	{
		return type;
	}
	void setType(const char* type)
	{
		if (type != nullptr)
		{
			if (this->type != nullptr)
			{
				delete[] this->type;
			}
			this->type = new char[strlen(type) + 1];
			strcpy(this->type, type);
		}
	}

	string* getConstraints()
	{
		return constraints;
	}
	void setConstraints(string* constraints, int nbOfConstraints)
	{
		if (constraints != nullptr && nbOfConstraints > 0)
		{
			this->nbOfConstraints = nbOfConstraints;
			this->constraints = new string[nbOfConstraints];
			for (int i = 0; i < nbOfConstraints; i++)
			{
				this->constraints[i] = constraints[i];
			}
		}
	}
	int getNbOfConstraints()
	{
		return nbOfConstraints;
	}

	int getNbOfNullValues()
	{
		return nbOfNullValues;
	}
	void setNbOfNullValues(int nbOfNullValues)
	{
		if (nbOfNullValues > 0)
		{
			this->nbOfNullValues = nbOfNullValues;
		}
	}

	friend ostream& operator<<(ostream&, Column);
	friend istream& operator>>(istream&, Column&);
	friend Column operator+(Column, Column);
};

//supraincarcare operator<<
ostream& operator<<(ostream& out, Column c)
{
	out << "Column name: ";
	if (c.name != nullptr)
	{
		out << c.name << endl;
	}
	else
	{
		out << "N/A" << endl;
	}

	out << "Data type: ";
	if (c.type != nullptr)
	{
		out << c.type << endl;
	}
	else
	{
		out << "N/A" << endl;
	}

	out << "Number of constraints: " << c.nbOfConstraints << endl;
	out << "Constraints: ";
	if (c.constraints != nullptr)
	{
		for (int i = 0; i < c.nbOfConstraints; i++)
		{
			out << c.constraints[i] << ", ";
		}
	}

	cout << endl;
	out << "Number of null values: " << c.nbOfNullValues;

	return out;
}

//supraincarcare operator>>
istream& operator>>(istream& in, Column& c)
{
	string buffer;
	cout << "Column name: ";
	in >> buffer;
	if (c.name != nullptr)
	{
		delete[] c.name;
	}
	c.name = new char[buffer.length() + 1];
	strcpy_s(c.name, buffer.length() + 1, buffer.c_str());

	string buffer2;
	cout << "Data type: ";
	in >> buffer2;
	if (c.type != nullptr)
	{
		delete[] c.type;
	}
	c.type = new char[buffer2.length() + 1];
	strcpy_s(c.type, buffer2.length() + 1, buffer2.c_str());

	cout << "Number of constraints: ";
	in >> c.nbOfConstraints;
	cout << "Constraints: " << endl;
	if (c.constraints != nullptr)
	{
		delete[] c.constraints;
	}
	if (in.good() && c.nbOfConstraints > 0)
	{
		c.constraints = new string[c.nbOfConstraints];
		for (int i = 0; i < c.nbOfConstraints; i++)
		{
			cout << "Constraint " << i + 1 << " : ";
			in >> ws;
			getline(in, c.constraints[i]);
		}
	}


	cout << "Number of null values: ";
	in >> c.nbOfNullValues;
	return in;
}

//supraincarcare operator+
Column operator+(Column c1, Column c2)
{
	c1.nbOfNullValues += c2.nbOfNullValues;
	return c1;
}



//CLASA 2
class Table
{
private:
	char* name; // numele tabelei
	int* ids; // valorile din coloana id 
	int nbOfIds; // numarul de id-uri
	Column* columns; // tabela are un array de coloane
	int nbOfColumns; // nr de coloane
	static int nbOfTables; // nr de tabele (creste de fiecare data cand se adauga o noua tabla)
public:
	//constructor implicit
	Table()
	{
		name = nullptr;
		ids = nullptr;
		columns = nullptr;
		nbOfColumns = 0;
		nbOfTables++;
	}

	//constructor 1 cu parametri
	Table(const char* name, int* ids, int nbOfIds, Column* columns, int nbOfColumns)
	{
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else
		{
			this->name = nullptr;
		}

		if (ids != nullptr && nbOfIds > 0)
		{
			this->nbOfIds = nbOfIds;
			this->ids = new int[nbOfIds];
			for (int i = 0; i < nbOfIds; i++)
			{
				this->ids[i] = ids[i];
			}
		}
		else
		{
			this->ids = nullptr;
			this->nbOfIds = 0;
		}

		if (columns != nullptr && nbOfColumns > 0)
		{
			this->nbOfColumns = nbOfColumns;
			this->columns = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				this->columns[i] = columns[i];
			}
		}
		nbOfTables++;
	}

	//constructor 2 cu paramteri
	Table(const char* name, Column* columns, int nbOfColumns)
	{
		if (name != nullptr)
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else
		{
			this->name = nullptr;
		}

		if (columns != nullptr && nbOfColumns > 0)
		{
			if (this->columns != nullptr)
			{
				delete[] columns;
			}

			this->nbOfColumns = nbOfColumns;
			this->columns = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				this->columns[i] = columns[i];
			}
		}
		this->ids = nullptr;
		this->nbOfIds = 0;
		nbOfTables++;
	}

	//constructor de copiere
	Table(const Table& t)
	{
		if (t.name != nullptr)
		{
			this->name = new char[strlen(t.name) + 1];
			strcpy_s(this->name, strlen(t.name) + 1, t.name);
		}
		else
		{
			this->name = nullptr;
		}

		if (t.ids != nullptr && t.nbOfIds > 0)
		{
			this->nbOfIds = t.nbOfIds;
			this->ids = new int[t.nbOfIds];
			for (int i = 0; i < t.nbOfIds; i++)
			{
				this->ids[i] = t.ids[i];
			}
		}
		else
		{
			this->ids = nullptr;
			this->nbOfIds = 0;
		}

		if (t.columns != nullptr && t.nbOfColumns > 0)
		{
			this->nbOfColumns = t.nbOfColumns;
			this->columns = new Column[t.nbOfColumns];
			for (int i = 0; i < t.nbOfColumns; i++)
			{
				this->columns[i] = t.columns[i];
			}
		}
		else
		{
			this->columns = nullptr;
			this->nbOfColumns = 0;
		}
		nbOfTables++;
	}

	//destructor
	~Table()
	{
		if (name != nullptr)
		{
			delete[] name;
		}

		if (ids != nullptr)
		{
			delete[] ids;
		}

		nbOfTables--;
	}

	//supraincarcare operator=
	Table& operator=(const Table& t)
	{
		if (name != nullptr)
		{
			delete[] name;
		}

		if (ids != nullptr)
		{
			delete[] ids;
		}

		if (t.name != nullptr)
		{
			this->name = new char[strlen(t.name) + 1];
			strcpy_s(this->name, strlen(t.name) + 1, t.name);
		}
		else
		{
			this->name = nullptr;
		}

		if (t.ids != nullptr && t.nbOfIds > 0)
		{
			this->nbOfIds = t.nbOfIds;
			this->ids = new int[t.nbOfIds];
			for (int i = 0; i < t.nbOfIds; i++)
			{
				this->ids[i] = t.ids[i];
			}
		}
		else
		{
			this->ids = nullptr;
			this->nbOfIds = 0;
		}

		if (t.columns != nullptr && t.nbOfColumns > 0)
		{
			this->nbOfColumns = t.nbOfColumns;
			this->columns = new Column[t.nbOfColumns];
			for (int i = 0; i < t.nbOfColumns; i++)
			{
				this->columns[i] = t.columns[i];
			}
		}
		else
		{
			this->columns = nullptr;
			this->nbOfColumns = 0;
		}

		nbOfTables++;
		return *this;
	}

	//supraincarcare operator[]
	int& operator[](int index)
	{
		if (index >= 0 && index < nbOfIds)
		{
			return ids[index];
		}
		throw exception("index invalid");
	}

	//supraincarcare operator++ preincrementare
	Table operator++()
	{
		this->nbOfIds++;
		return *this;
	}

	//supraincarcare operator++ postincrementare
	Table operator++(int i)
	{
		Table copy = *this;
		this->nbOfIds++;
		return copy;
	}

	//supraincarcare operator cast
	operator char* ()
	{
		return name;
	}

	//supraincarcare operator!
	bool operator!()
	{
		return nbOfIds > 0;
	}

	//supraincrcare operator>
	bool operator>(const Table& t)
	{
		if (nbOfColumns > t.nbOfColumns)
		{
			return true;
		}
		return false;
	}

	//apel operator==
	bool operator==(const Table& t)
	{
		if (nbOfIds == t.nbOfIds)
		{
			return true;
		}
		return false;
	}

	char* getName()
	{
		if (name != nullptr)
		{
			char* copie = new char[strlen(name) + 1];
			strcpy_s(copie, strlen(name) + 1, name);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setName(char* name)
	{
		if (name != nullptr)
		{
			if (this->name != nullptr)
			{
				delete[] this->name;
			}
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}

	int* getIds()
	{
		if (ids != nullptr)
		{
			int* copie = new int[nbOfIds];
			for (int i = 0; i < nbOfIds; i++)
			{
				copie[i] = ids[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setIds(int* ids, int nbOfIds)
	{
		if (ids != nullptr && nbOfIds > 0)
		{
			this->nbOfIds = nbOfIds;
			if (this->ids != nullptr)
			{
				delete[] this->ids;
			}
			this->ids = new int[nbOfIds];
			for (int i = 0; i < nbOfIds; i++)
			{
				this->ids[i] = ids[i];
			}
		}
	}
	int getNbOfIds()
	{
		return nbOfIds;
	}

	void setColumns(Column* columns, int nbOfColumns)
	{
		if (columns != nullptr && nbOfColumns > 0)
		{
			if (this->columns != nullptr)
			{
				delete[] columns;
			}
			this->nbOfColumns = nbOfColumns;
			this->columns = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				this->columns[i] = columns[i];
			}
		}
	}
	Column* getColumns()
	{
		if (columns != nullptr)
		{
			Column* copy = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				copy[i] = columns[i];
			}
			return copy;
		}
		else
		{
			return nullptr;
		}
	}
	int getNbOfColumns()
	{
		return nbOfColumns;
	}

	static int getNbOfTables()
	{
		return nbOfTables;
	}
	static void setNbOfTables(int nbOfTables)
	{
		Table::nbOfTables = nbOfTables;
	}

	friend ostream& operator<<(ostream&, Table);
	friend istream& operator>>(istream&, Table&);
	friend Table operator+(Table, Table);
};

//initializare atribut static
int Table::nbOfTables = 0;

//supraincarcare operator+
Table operator+(Table t1, Table t2)
{
	t1.nbOfIds += t2.nbOfIds;
	return t1;
}

//supraincarcare operator<<
ostream& operator<<(ostream& out, Table t)
{
	out << "Name: ";
	if (t.name != nullptr)
	{
		out << t.name << endl;
	}
	else
	{
		out << "N/A" << endl;
	}

	out << "Number of ids: " << t.nbOfIds << endl;
	out << "Ids: ";
	if (t.ids != nullptr)
	{
		for (int i = 0; i < t.nbOfIds; i++)
		{
			out << t.ids[i] << " ";
		}
	}
	else
	{
		out << "N/A";
	}
	out << endl;

	out << "Number of columns: " << t.nbOfColumns << endl;
	out << "Columns: " << endl;
	if (t.columns != nullptr)
	{
		for (int i = 0; i < t.nbOfColumns; i++)
		{
			out << "Column " << i + 1 << ": " << endl;
			out << t.columns[i] << " " << endl;
		}
	}
	else
	{
		out << "N/A";
	}
	out << endl;

	out << "Number of tables: " << t.nbOfTables << endl;

	return out;
}

//supraincarcare operator>>
istream& operator>>(istream& in, Table& t)
{
	string buffer;
	cout << "Nume: ";
	in >> buffer;
	if (t.name != nullptr)
	{
		delete[] t.name;
	}
	t.name = new char[buffer.length() + 1];
	strcpy_s(t.name, buffer.length() + 1, buffer.c_str());

	cout << "Number of ids: ";
	in >> t.nbOfIds;
	if (t.ids != nullptr)
	{
		delete[] t.ids;
	}
	if (in.good() && t.nbOfIds > 0)
	{
		t.ids = new int[t.nbOfIds];
		for (int i = 0; i < t.nbOfIds; i++)
		{
			cout << "ids[" << i << "] = ";
			in >> t.ids[i];
		}
	}
	else
	{
		t.ids = nullptr;
		t.nbOfIds = 0;
	}

	cout << "Number of columns: ";
	in >> t.nbOfColumns;
	if (t.nbOfColumns > 0)
	{
		if (t.columns != nullptr)
		{
			delete[] t.columns;
		}
		t.columns = new Column[t.nbOfColumns];
		for (int i = 0; i < t.nbOfColumns; i++)
		{
			cout << "Column " << i + 1 << ": " << endl;
			in >> t.columns[i];
		}
	}

	return in;
}



//CLASA 3 
class Row
{
private:
	int id;
	char* tableName; // numele tabelei din care face parte randul
	Column* columns; // un rand are o lista de coloane
	int nbOfColumns; //nr de coloane
public:
	//constructor implicit
	Row()
	{
		id = 0;
		tableName = nullptr;
		columns = nullptr;
		nbOfColumns = 0;
	}

	//constructor 1 cu parametri
	Row(int id, const char* tableName, Column* columns, int nbOfColumns)
	{
		this->id = id;

		if (tableName != nullptr)
		{
			this->tableName = new char[strlen(tableName) + 1];
			strcpy(this->tableName, tableName);
		}
		else
		{
			this->tableName = nullptr;
		}

		if (columns != nullptr && nbOfColumns > 0)
		{
			this->nbOfColumns = nbOfColumns;
			this->columns = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				this->columns[i] = columns[i];
			}
		}
		else
		{
			this->columns = nullptr;
			this->nbOfColumns = 0;
		}
	}

	//constructor 2 cu parametri
	Row(const char* tableName) :Row()
	{
		if (tableName != nullptr)
		{
			this->tableName = new char[strlen(tableName) + 1];
			strcpy(this->tableName, tableName);
		}
		else
		{
			this->tableName = nullptr;
		}
	}

	//constructor de copiere
	Row(const Row& r)
	{
		this->id = r.id;

		if (r.tableName != nullptr)
		{
			this->tableName = new char[strlen(r.tableName) + 1];
			strcpy(this->tableName, r.tableName);
		}
		else
		{
			this->tableName = nullptr;
		}

		if (r.columns != nullptr && r.nbOfColumns > 0)
		{
			this->nbOfColumns = r.nbOfColumns;
			this->columns = new Column[r.nbOfColumns];
			for (int i = 0; i < r.nbOfColumns; i++)
			{
				this->columns[i] = r.columns[i];
			}
		}
		else
		{
			this->columns = nullptr;
			this->nbOfColumns = 0;
		}
	}

	//supraincarcare operator=
	Row& operator=(const Row& r)
	{
		if (columns != nullptr)
		{
			delete[] columns;
		}
		if (tableName != nullptr)
		{
			delete[] tableName;
		}

		this->id = r.id;

		if (r.tableName != nullptr)
		{
			this->tableName = new char[strlen(r.tableName) + 1];
			strcpy(this->tableName, r.tableName);
		}
		else
		{
			this->tableName = nullptr;
		}

		if (r.columns != nullptr && r.nbOfColumns > 0)
		{
			this->nbOfColumns = r.nbOfColumns;
			this->columns = new Column[r.nbOfColumns];
			for (int i = 0; i < r.nbOfColumns; i++)
			{
				this->columns[i] = r.columns[i];
			}
		}
		else
		{
			this->columns = nullptr;
			this->nbOfColumns = 0;
		}
		return *this;
	}

	//destructor
	~Row()
	{
		if (columns != nullptr)
		{
			delete[] columns;
		}
		if (tableName != nullptr)
		{
			delete[] tableName;
		}
	}

	//supraincarcare operator[]
	Column& operator[](int index)
	{
		if (index >= 0 && index < nbOfColumns)
		{
			return columns[index];
		}
		throw exception("index invalid");
	}

	//supraincarcare operator+
	Row operator+(int value)
	{
		if (value > 0)
		{
			Row copy = *this;
			Column* columnsCopy = new Column[copy.nbOfColumns + value];
			for (int i = 0; i < copy.nbOfColumns; i++)
			{
				columnsCopy[i] = copy.columns[i];
			}
			copy.columns = columnsCopy;
			copy.nbOfColumns += value;

			return copy;
		}
		throw - 1;
	}

	//supraincarcare operator cast
	operator char* ()
	{
		return tableName;
	}

	//supraincarcare operator!
	bool operator!()
	{
		return nbOfColumns > 0;
	}

	//supraincarcare operator>
	bool operator>(const Row& r)
	{
		if (nbOfColumns > r.nbOfColumns)
		{
			return true;
		}
		return false;
	}

	//supraincarcare operator==
	bool operator==(const Row& r)
	{
		if (strcmp(tableName, r.tableName) == 0)
		{
			return true;
		}
		return false;
	}

	int getId()
	{
		return id;
	}
	void setId(int id)
	{
		this->id = id;
	}

	char* getTableName()
	{
		if (tableName != nullptr)
		{
			char* copie = new char[strlen(tableName) + 1];
			strcpy_s(copie, strlen(tableName) + 1, tableName);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setTableName(const char* tableName)
	{
		if (tableName != nullptr)
		{
			if (this->tableName != nullptr)
			{
				delete[] this->tableName;
			}
			this->tableName = new char[strlen(tableName) + 1];
			strcpy_s(this->tableName, strlen(tableName) + 1, tableName);
		}
	}

	void setColumns(Column* columns, int nbOfColumns)
	{
		if (columns != nullptr && nbOfColumns > 0)
		{
			if (this->columns != nullptr)
			{
				delete[] columns;
			}
			this->nbOfColumns = nbOfColumns;
			this->columns = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				this->columns[i] = columns[i];
			}
		}
	}
	Column* getColumns()
	{
		if (columns != nullptr)
		{
			Column* copy = new Column[nbOfColumns];
			for (int i = 0; i < nbOfColumns; i++)
			{
				copy[i] = columns[i];
			}
			return copy;
		}
		else
		{
			return nullptr;
		}
	}
	int getNbOfColumns()
	{
		return nbOfColumns;
	}

	friend ostream& operator<<(ostream&, Row);
	friend istream& operator>>(istream&, Row&);
	friend Row operator+(int, Row);
};

//supraincarcare operator<<
ostream& operator<<(ostream& out, Row r)
{
	out << "Id: " << r.id << endl;

	out << "Table name: ";
	if (r.tableName != nullptr)
	{
		out << r.tableName << endl;
	}
	else
	{
		out << "N/A" << endl;
	}
	out << "Number of columns: " << r.nbOfColumns << endl;
	out << "Columns: " << endl;
	if (r.columns != nullptr)
	{
		for (int i = 0; i < r.nbOfColumns; i++)
		{
			out << "Column " << i + 1 << ": " << endl;
			out << r.columns[i] << " " << endl;
		}
	}
	else
	{
		out << "N/A";
	}
	out << endl;
	return out;
}

//supraincarcare operator>>
istream& operator>>(istream& in, Row& r)
{
	cout << "Id: ";
	in >> r.id;

	string buffer;
	cout << "Table name: ";
	in >> buffer;
	if (r.tableName != nullptr)
	{
		delete[] r.tableName;
	}
	r.tableName = new char[buffer.length() + 1];
	strcpy_s(r.tableName, buffer.length() + 1, buffer.c_str());

	cout << "Number of columns: ";
	in >> r.nbOfColumns;
	if (r.nbOfColumns > 0)
	{
		if (r.columns != nullptr)
		{
			delete[] r.columns;
		}
		r.columns = new Column[r.nbOfColumns];
		for (int i = 0; i < r.nbOfColumns; i++)
		{
			cout << "Column " << i + 1 << ": " << endl;
			in >> r.columns[i];
		}
	}
	return in;
}

//comutativitatea operatorului+
Row operator+(int value, Row r)
{
	if (value > 0)
	{
		Column* columnsCopy = new Column[r.nbOfColumns + value];
		for (int i = 0; i < r.nbOfColumns; i++)
		{
			columnsCopy[i] = r.columns[i];
		}
		r.columns = columnsCopy;
		r.nbOfColumns += value;
		return r;
	}
	throw - 1;
}



//CLASA 4
class Command
{
private:
	char* type; //DDL, DML,DCL etc
	string* parameters; //parametrii comenzii (string array de stringuri)
	int nbOfParameters; //nb de parametri
	int nbOfCalls; //de cate ori a fost apelata comanda
public:
	//constructor implicit
	Command()
	{
		type = nullptr;
		parameters = nullptr;
		nbOfParameters = 0;
		nbOfCalls = 0;
	}

	//constructor 1 cu parametri
	Command(const char* type, string* parameters, int nbOfParameters, int nbOfCalls)
	{
		if (type != nullptr)
		{
			this->type = new char[strlen(type) + 1];
			strcpy_s(this->type, strlen(type) + 1, type);
		}
		else
		{
			this->type = nullptr;
		}

		if (parameters != nullptr && nbOfParameters > 0)
		{
			this->nbOfParameters = nbOfParameters;
			this->parameters = new string[nbOfParameters];
			for (int i = 0; i < nbOfParameters; i++)
			{
				this->parameters[i] = parameters[i];
			}
		}
		else
		{
			this->parameters = nullptr;
			this->nbOfParameters = 0;
		}

		this->nbOfCalls = nbOfCalls;
	}

	//constructor 2 cu parametri
	Command(string* parameters, int nbOfParameters) : Command()
	{
		if (parameters != nullptr && nbOfParameters > 0)
		{
			this->nbOfParameters = nbOfParameters;
			this->parameters = new string[nbOfParameters];
			for (int i = 0; i < nbOfParameters; i++)
			{
				this->parameters[i] = parameters[i];
			}
		}
		else
		{
			this->parameters = nullptr;
			this->nbOfParameters = 0;
		}
	}

	//constructor de copiere
	Command(const Command& comm)
	{
		if (comm.type != nullptr)
		{
			this->type = new char[strlen(comm.type) + 1];
			strcpy_s(this->type, strlen(comm.type) + 1, comm.type);
		}
		else
		{
			this->type = nullptr;
		}

		if (comm.parameters != nullptr && comm.nbOfParameters > 0)
		{
			this->nbOfParameters = comm.nbOfParameters;
			this->parameters = new string[comm.nbOfParameters];
			for (int i = 0; i < comm.nbOfParameters; i++)
			{
				this->parameters[i] = comm.parameters[i];
			}
		}
		else
		{
			this->parameters = nullptr;
			this->nbOfParameters = 0;
		}

		this->nbOfCalls = comm.nbOfCalls;
	}

	//supraincarcare operator=
	Command& operator=(const Command& comm)
	{
		if (type != nullptr)
		{
			delete[] type;
		}
		if (parameters != nullptr)
		{
			delete[] parameters;
		}

		if (comm.type != nullptr)
		{
			this->type = new char[strlen(comm.type) + 1];
			strcpy_s(this->type, strlen(comm.type) + 1, comm.type);
		}
		else
		{
			this->type = nullptr;
		}

		if (comm.parameters != nullptr && comm.nbOfParameters > 0)
		{
			this->nbOfParameters = comm.nbOfParameters;
			this->parameters = new string[comm.nbOfParameters];
			for (int i = 0; i < comm.nbOfParameters; i++)
			{
				this->parameters[i] = comm.parameters[i];
			}
		}
		else
		{
			this->parameters = nullptr;
			this->nbOfParameters = 0;
		}

		this->nbOfCalls = comm.nbOfCalls;

		return *this;
	}

	//destructor
	~Command()
	{
		if (type != nullptr)
		{
			delete[] type;
		}
		if (parameters != nullptr)
		{
			delete[] parameters;
		}
	}

	//supraincarcare operator[]
	string& operator[](int index)
	{
		if (index >= 0 && index < nbOfParameters)
		{
			return parameters[index];
		}
		throw exception("index invalid");
	}

	//supraincarcare operator+
	Command operator+(int value)
	{
		if (value > 0)
		{
			Command copy = *this;
			string* parametersCopy = new string[copy.nbOfParameters + value];
			for (int i = 0; i < copy.nbOfParameters; i++)
			{
				parametersCopy[i] = copy.parameters[i];
			}
			copy.parameters = parametersCopy;

			copy.nbOfParameters += value;

			return copy;
		}
	}

	//supraincarcare operator++ preincremetare
	Command operator++()
	{
		this->nbOfCalls++;
		return *this;
	}

	//supraincarcare operator++ postincremetare
	Command operator++(int i)
	{
		Command copy = *this;
		this->nbOfCalls++;
		return copy;
	}

	//supraincarcare operator cast
	operator int()
	{
		return nbOfParameters;
	}

	//supraincarcare operator!
	bool operator!()
	{
		return nbOfCalls > 0;
	}

	//supraincarcare operator>
	bool operator>=(const Command& comm)
	{
		if (nbOfParameters >= comm.nbOfParameters)
		{
			return true;
		}
		return false;
	}

	//supraincarcare operator==
	bool operator==(const Command& comm)
	{
		if (nbOfParameters == comm.nbOfParameters)
		{
			return true;
		}
		return false;
	}

	char* getType()
	{
		return type;
	}
	void setType(const char* type)
	{
		if (type != nullptr)
		{
			if (this->type != nullptr)
			{
				delete[] this->type;
			}
			this->type = new char[strlen(type) + 1];
			strcpy_s(this->type, strlen(type) + 1, type);
		}
	}

	string* getParameters()
	{
		return parameters;
	}
	int getNbOfParameters()
	{
		return nbOfParameters;
	}
	void setParameters(string* parameters, int nbOfParameters)
	{
		if (parameters != nullptr && nbOfParameters > 0)
		{
			if (this->parameters != nullptr)
			{
				delete[] this->parameters;
			}
			this->nbOfParameters = nbOfParameters;
			this->parameters = new string[nbOfParameters];
			for (int i = 0; i < nbOfParameters; i++)
			{
				this->parameters[i] = parameters[i];
			}
		}
	}

	int getNbOfCalls()
	{
		return nbOfCalls;
	}
	void setNbOfCalls(int nbOfCalls)
	{
		if (nbOfCalls >= 0)
		{
			this->nbOfCalls = nbOfCalls;
		}
	}

	friend ostream& operator<<(ostream&, Command);
	friend istream& operator>>(istream&, Command&);
	friend Command operator+(int, Command);
};

//supraincarcare operator<<
ostream& operator<<(ostream& out, Command comm)
{
	out << "Type of statement: ";
	if (comm.type != nullptr)
	{
		out << comm.type << endl;
	}
	else
	{
		out << "N/A" << endl;
	}

	out << "Number of parameters: " << comm.nbOfParameters << endl;
	out << "Parameters: ";
	if (comm.parameters != nullptr)
	{
		for (int i = 0; i < comm.nbOfParameters; i++)
		{
			out << comm.parameters[i] << ", ";
		}
	}

	out << endl;
	out << "Number of calls: " << comm.nbOfCalls << endl;

	return out;
}

//supraincarcare operator>>
istream& operator>>(istream& in, Command& comm)
{
	char buffer[100];
	cout << "Type of statement : ";
	in >> ws;
	in.getline(buffer, 99);
	if (comm.type != nullptr)
	{
		delete[] comm.type;
	}
	comm.type = new char[strlen(buffer) + 1];
	strcpy_s(comm.type, strlen(buffer) + 1, buffer);

	cout << "Number of parameters: ";
	in >> comm.nbOfParameters;
	cout << "Parameters: " << endl;
	if (comm.parameters != nullptr)
	{
		delete[] comm.parameters;
	}
	if (in.good() && comm.nbOfParameters > 0)
	{
		comm.parameters = new string[comm.nbOfParameters];
		for (int i = 0; i < comm.nbOfParameters; i++)
		{
			cout << "Parameter " << i + 1 << " : ";
			in >> comm.parameters[i];
			//PARAMETRII NU SE SCRIU CU SPATII IN SQL
			/*in >> ws;
			getline(in, comm.parameters[i]);*/
		}
	}

	cout << "Number of calls: ";
	in >> comm.nbOfCalls;

	return in;
}

//comutativitate operator+
Command operator+(int value, Command comm)
{
	if (value > 0)
	{
		string* parametersCopy = new string[comm.nbOfParameters + value];
		for (int i = 0; i < comm.nbOfParameters; i++)
		{
			parametersCopy[i] = comm.parameters[i];
		}
		comm.parameters = parametersCopy;
		comm.nbOfParameters += value;
		return comm;
	}
}



//CLASA 5
class Connection
{
private:
	int* userConnectedIds; //lista cu id-urile userilor care s-au conectat la baza de date
	int nbOfConnections; //nr de useri conectati(nr de id-uri)
	const string hostname; //numele host-ul care realizeaza conexiunea
	int port; //port-ul conexiunii
public:
	//constructor implicit
	Connection() : hostname("localhost")
	{
		userConnectedIds = nullptr;
		nbOfConnections = 0;
		port = 0;
	}

	//constructor 1 cu parametri
	Connection(int* userConnectedIds, int nbOfConnections, string hostname, int port) : hostname(hostname)
	{
		if (userConnectedIds != nullptr && nbOfConnections > 0)
		{
			this->userConnectedIds = new int[nbOfConnections];
			this->nbOfConnections = nbOfConnections;
			for (int i = 0; i < nbOfConnections; i++)
			{
				this->userConnectedIds[i] = userConnectedIds[i];
			}
		}
		else
		{
			this->userConnectedIds = nullptr;
			this->nbOfConnections = 0;
		}

		this->port = port;
	}

	//constructor 2 cu parametri
	Connection(string hostname, int port) : Connection()
	{
		this->port = port;
	}

	//constructor de copiere
	Connection(const Connection& con) :hostname(con.hostname)
	{
		if (con.userConnectedIds != nullptr && con.nbOfConnections > 0)
		{
			this->userConnectedIds = new int[con.nbOfConnections];
			this->nbOfConnections = con.nbOfConnections;
			for (int i = 0; i < con.nbOfConnections; i++)
			{
				this->userConnectedIds[i] = con.userConnectedIds[i];
			}
		}
		else
		{
			this->userConnectedIds = nullptr;
			this->nbOfConnections = 0;
		}

		this->port = con.port;
	}

	//supraincarcare operator=
	Connection& operator=(const Connection& con)
	{
		if (userConnectedIds != nullptr)
		{
			delete[] userConnectedIds;
		}

		if (con.userConnectedIds != nullptr && con.nbOfConnections > 0)
		{
			this->userConnectedIds = new int[con.nbOfConnections];
			this->nbOfConnections = con.nbOfConnections;
			for (int i = 0; i < con.nbOfConnections; i++)
			{
				this->userConnectedIds[i] = con.userConnectedIds[i];
			}
		}
		else
		{
			this->userConnectedIds = nullptr;
			this->nbOfConnections = 0;
		}

		this->port = con.port;

		return *this;
	}

	//destructor
	~Connection()
	{
		if (userConnectedIds != nullptr)
		{
			delete[] userConnectedIds;
		}

	}

	//supraincarcare operator[]
	int& operator[](int index)
	{
		if (index >= 0 && index < nbOfConnections)
		{
			return userConnectedIds[index];
		}
		throw exception("index invalid");
	}

	//supraincarcare operator+
	Connection operator+(int value)
	{
		if (value > 0)
		{
			Connection copy = *this;
			copy.port += value;
			return copy;
		}
	}

	//supraincarcare operator++ preincrementare
	Connection operator++()
	{
		this->nbOfConnections++;
		return *this;
	}

	//supraincarcare operator++ postincrementare
	Connection operator++(int i)
	{
		Connection copy = *this;
		this->nbOfConnections++;
		return copy;
	}

	//supraincarcare operator cast
	operator int()
	{
		return port;
	}

	//supraincarcare operator!
	bool operator!()
	{
		return nbOfConnections > 0;
	}

	//supraincarcare operator<
	bool operator<(const Connection& con)
	{
		if (nbOfConnections < con.nbOfConnections)
		{
			return true;
		}
		return false;
	}

	//supraincarcare operator==
	bool operator==(const Connection& con)
	{
		if (nbOfConnections == con.nbOfConnections)
		{
			return true;
		}
		return false;
	}

	int* getUserConnectedIds()
	{
		if (userConnectedIds != nullptr)
		{
			int* copy = new int[nbOfConnections];
			for (int i = 0; i < nbOfConnections; i++)
			{
				copy[i] = userConnectedIds[i];
			}
			return copy;
		}
		return nullptr;
	}
	void setUserConnectedIds(int* userConnectedIds, int nbOfConnections)
	{
		if (userConnectedIds != nullptr && nbOfConnections > 0)
		{
			if (this->userConnectedIds != nullptr)
			{
				delete[] this->userConnectedIds;
			}
			this->nbOfConnections = nbOfConnections;
			this->userConnectedIds = new int[nbOfConnections];
			for (int i = 0; i < nbOfConnections; i++)
			{
				this->userConnectedIds[i] = userConnectedIds[i];
			}
		}
	}
	int getNbOfConnections()
	{
		return nbOfConnections;
	}

	int getPort()
	{
		return port;
	}
	void setPort(int port)
	{
		if (port > 0)
		{
			this->port = port;
		}
	}

	friend ostream& operator<<(ostream&, Connection);
	friend istream& operator>>(istream&, Connection&);
	friend Connection operator+(int, Connection);
};

//supraincarcare operator<<
ostream& operator<<(ostream& out, Connection con)
{
	out << "Number of connected users: " << con.nbOfConnections << endl;
	out << "Users IDs: ";
	if (con.userConnectedIds != nullptr)
	{
		for (int i = 0; i < con.nbOfConnections; i++)
		{
			out << con.userConnectedIds[i] << " ";
		}
	}
	else
	{
		out << "N/A";
	}
	out << endl;

	out << "Host name: " << con.hostname << endl;

	out << "Port: " << con.port << endl;

	return out;
}

//supraincarcare operator>>
istream& operator>>(istream& in, Connection& con)
{
	cout << "Number of connected users: ";
	in >> con.nbOfConnections;
	if (con.userConnectedIds != nullptr)
	{
		delete[] con.userConnectedIds;
	}
	if (in.good() && con.nbOfConnections > 0)
	{
		con.userConnectedIds = new int[con.nbOfConnections];
		for (int i = 0; i < con.nbOfConnections; i++)
		{
			cout << "User " << i + 1 << ": ";
			in >> con.userConnectedIds[i];
		}
	}
	else
	{
		con.userConnectedIds = nullptr;
		con.nbOfConnections = 0;
	}

	cout << "Port: ";
	in >> con.port;

	return in;
}

//comutativitate operator+
Connection operator+(int value, Connection con)
{
	con.port += value;
	return con;
}

class SqlCommand {

public:
	// verificare sintaxe SQL
	void toLowerCase(char* query)
	{
		for (int i = 0; i < strlen(query); ++i)
		{
			query[i] = tolower(query[i]);
		}
	}

	char* detectCommand(char* query) {
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* token = strtok(queryLowerCase, " ");
		char* command = new char[strlen(token) + 1];
		strcpy(command, token);

		if (strcmp(token, "create") == 0 || strcmp(token, "drop") == 0)
		{
			token = strtok(NULL, " ");
			if (token == nullptr)
			{
				return nullptr;
			}
			strcat(command, " ");
			strcat(command, token);
		}
		return command;
	}

	bool checkCreateTableQuery(char* query)
	{
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* queryArray[1000];
		int i = 0;

		char* token = strtok(queryLowerCase, " ");
		queryArray[i] = new char[strlen(token) + 1];
		strcpy(queryArray[i], token);

		while (token != nullptr)
		{
			token = strtok(NULL, " ");
			if (token != nullptr)
			{
				i++;
				queryArray[i] = new char[strlen(token) + 1];
				strcpy(queryArray[i], token);
			}
		}

		if (strcmp(queryArray[0], "create") != 0)
		{
			return false;
		}

		if (strcmp(queryArray[1], "table") != 0)
		{
			return false;
		}

		if (i < 2 || queryArray[2] == nullptr || (strcmp(queryArray[2], "if") != 0 && i < 3))
		{
			return false;
		}
		else if (strcmp(queryArray[2], "if") == 0)
		{
			if ((strcmp(queryArray[3], "not") != 0 && strcmp(queryArray[4], "exists") != 0) ||
				(i < 6 || queryArray[4] == nullptr))
				return false;
		}

		return true;
	}

	bool checkDisplayTableQuery(char* query)
	{
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* queryArray[1000];
		int i = 0;

		char* token = strtok(queryLowerCase, " ");
		queryArray[i] = new char[strlen(token) + 1];
		strcpy(queryArray[i], token);

		while (token != nullptr)
		{
			token = strtok(NULL, " ");
			if (token != nullptr)
			{
				i++;
				queryArray[i] = new char[strlen(token) + 1];
				strcpy(queryArray[i], token);
			}
		}

		if (strcmp(queryArray[0], "display") != 0)
		{
			return false;
		}
		if (i < 1 || strcmp(queryArray[1], "table") != 0)
		{
			return false;
		}

		if (i < 2 || queryArray[2] == nullptr)
		{
			return false;
		}

		return true;
	}

	bool checkDropTableQuery(char* query)
	{
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* queryArray[1000];
		int i = 0;

		char* token = strtok(queryLowerCase, " ");
		queryArray[i] = new char[strlen(token) + 1];
		strcpy(queryArray[i], token);

		while (token != nullptr)
		{
			token = strtok(NULL, " ");
			if (token != nullptr)
			{
				i++;
				queryArray[i] = new char[strlen(token) + 1];
				strcpy(queryArray[i], token);
			}
		}

		if (strcmp(queryArray[0], "drop") != 0)
		{
			return false;
		}
		if (strcmp(queryArray[1], "table") != 0)
		{
			return false;
		}

		if (i < 2 || queryArray[2] == nullptr)
		{
			return false;
		}

		return true;
	}

	bool checkCreateIndexQuery(char* query)
	{
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* queryArray[1000];
		int i = 0;

		char* token = strtok(queryLowerCase, " ");
		queryArray[i] = new char[strlen(token) + 1];
		strcpy(queryArray[i], token);

		while (token != nullptr)
		{
			token = strtok(NULL, " ");
			if (token != nullptr)
			{
				i++;
				queryArray[i] = new char[strlen(token) + 1];
				strcpy(queryArray[i], token);
			}
		}

		if (strcmp(queryArray[0], "create") != 0)
		{
			return false;
		}

		if (strcmp(queryArray[1], "index") != 0)
		{
			return false;
		}

		if (i < 2 || queryArray[2] == nullptr || (strcmp(queryArray[2], "if") != 0 && i < 2))
		{
			return false;
		}
		else if (strcmp(queryArray[2], "if") == 0)
		{
			if ((strcmp(queryArray[3], "not") != 0 && strcmp(queryArray[4], "exists") != 0) ||
				(i != 5 || queryArray[4] == nullptr))
				return false;
		}

		return true;
	}

	bool checkDropIndexQuery(char* query)
	{
		toLowerCase(query);

		char* queryLowerCase = new char[strlen(query) + 1];
		strcpy(queryLowerCase, query);

		char* queryArray[1000];
		int i = 0;

		char* token = strtok(queryLowerCase, " ");
		queryArray[i] = new char[strlen(token) + 1];
		strcpy(queryArray[i], token);

		while (token != nullptr)
		{
			token = strtok(NULL, " ");
			if (token != nullptr)
			{
				i++;
				queryArray[i] = new char[strlen(token) + 1];
				strcpy(queryArray[i], token);
			}
		}

		if (strcmp(queryArray[0], "drop") != 0)
		{
			return false;
		}
		if (strcmp(queryArray[1], "index") != 0)
		{
			return false;
		}

		if (i > 2 || queryArray[2] == nullptr)
		{
			return false;
		}

		return true;
	}
};


int main()
{


	/////TESTARE CLASA COLUMN/////
	cout << "COLUMN" << endl;

	char* s1 = new char[strlen("Not null") + 1];
	char* s2 = new char[strlen("Primary key") + 1];
	char* s3 = new char[strlen("Foreign key") + 1];
	char* s4 = new char[strlen("Check") + 1];
	char* s5 = new char[strlen("Unique") + 1];

	strcpy(s1, "Not null");
	strcpy(s2, "Primary key");
	strcpy(s3, "Foreign key");
	strcpy(s4, "Check");
	strcpy(s5, "Unique");

	string constraints[] = { s1, s2, s3, s4 };
	string constraints2[] = { s1, s2, s3, s4, s5 };

	//apel constructor 1 cu parametri
	Column c1 = Column("Name", "Varchar2(20)", constraints, 4, 5);

	//apel constructor 2 cu parametri
	Column c = Column("Surname", "Varchar2(25)");

	//apel constructor de copiere
	Column c4 = c1;

	//apel operator=
	Column c5;
	c5 = c4;

	//apel getteri si setteri
	Column c2;
	c2.setName("ID");
	cout << "Apel getName: " << c2.getName() << endl;
	c2.setType("Number(5)");
	cout << "Apel getType: " << c2.getType() << endl;
	c2.setConstraints(constraints, 4);
	cout << "Apel getNbOfConstraints: " << c2.getNbOfConstraints() << endl;
	cout << "Apel getConstraints: ";
	for (int i = 0; i < c2.getNbOfConstraints(); i++)
	{
		cout << c2.getConstraints()[i] << ", ";
	}
	cout << endl;
	c2.setNbOfNullValues(0);
	cout << "Apel getNbOfNullValues: " << c2.getNbOfNullValues() << endl;
	cout << endl;

	//apel operator[]
	c2[2] = "Unique";
	cout << "Apel operator[]: " << c2[2] << endl;

	//apel operator+
	Column c7 = Column("Name", "Varchar2(20)", constraints2, 5, 10);
	Column c8 = c7 + c1;
	cout << "Apel operator+: " << c8.getNbOfNullValues() << endl;

	//apel operator-- 
	Column c9 = --c7;
	cout << "Apel operator de preincrementare: " << c9.getNbOfNullValues() << endl;
	Column c10 = c8--;
	cout << "Apel operator de postincrementare: " << c10.getNbOfNullValues() << endl;

	//apel operator cast
	int NullValues = c1;
	cout << "Apel operator cast: " << NullValues << endl;

	//apel operator!
	bool hasConstraints = !c2;
	cout << "Apel operator!: " << hasConstraints << endl;

	//apel operator<
	cout << "Apel operator<: ";
	if (c1 < c7)
	{
		cout << "First column has less constraints than the second" << endl;
	}
	else
	{
		cout << "First column has more constraints than the second" << endl;
	}

	//apel operator==
	cout << "Apel operator==: ";
	if (c1 == c)
	{
		cout << "Columns have the same type of data" << endl;
	}
	else
	{
		cout << "Columns don't have the same type of data" << endl;
	}
	cout << endl;

	//apel operator>> si <<
	Column c6;
	cout << "Apel operator>>" << endl;
	cin >> c6;
	cout << endl << "Apel operator<<" << endl;
	cout << c6 << endl;


	/////TESTARE CLASA TABLE/////
	cout << endl << "TABLE" << endl;
	Table t;
	int ids[] = { 10, 11, 12 };
	int ids2[] = { 10, 11, 12, 13 };

	//apel getteri si setteri
	char* a = new char[strlen("Students") + 1];
	strcpy(a, "Students");
	t.setName(a);
	cout << "Apel getName: " << t.getName() << endl;

	t.setIds(ids2, 4);
	cout << "Apel getNbOfIds: " << t.getNbOfIds() << endl;
	cout << "Apel getIds: ";
	for (int i = 0; i < t.getNbOfIds(); i++)
	{
		cout << t.getIds()[i] << " ";
	}
	cout << endl;

	Column columns[] = { c,c1 };
	t.setColumns(columns, 2);
	cout << "Apel getNbOfColumns: " << t.getNbOfColumns() << endl;
	cout << "Apel getColumns: " << endl;
	for (int i = 0; i < t.getNbOfColumns(); i++)
	{
		cout << "Column " << i + 1 << endl;
		cout << t.getColumns()[i] << " " << endl;
	}
	cout << endl;

	string constr[] = { s1 };
	Column col1 = Column("ID", "Number(5)");
	Column col2 = Column("Group", "Varchar2(10)");
	Column col3 = Column("Course", "Varchar2(15)");
	Column col4 = Column("CNP", "char(10)", constr, 1, 0);
	Column columns2[] = { col1, col2 };
	Column columns3[] = { col1, col2, col3 };
	Column columns4[] = { col1, col2, col3, col4 };

	//apel constructor 1 cu parametri
	Table t1(a, ids, 3, columns2, 2);

	//apel constructor 2 cu parametri
	Table t2(a, columns3, 3);

	//apel constructor de copiere
	Table t3 = t1;

	//apel operator=
	Table t4;
	t4 = t2;

	//apel operator[]
	t3[1] = 20;
	cout << "Apel operator[]: " << t3[1] << endl;

	//apel operator+
	Table t6 = t1 + t3;
	cout << "Apel operator+: " << t6.getNbOfIds() << endl;

	//apel operator++ 
	Table t7 = ++t1;
	cout << "Apel operator++ preincrementare: " << t7.getNbOfIds() << endl;
	Table t8 = t3++;
	cout << "Apel operator++ postincrementare: " << t8.getNbOfIds() << endl;

	//apel operator cast
	char* TableName = t1;
	cout << "Apel operator cast: " << TableName << endl;

	//apel operator!
	bool hasIds = !t2;
	cout << "Apel operator!: " << hasIds << endl;

	//apel operator>
	cout << "Apel operator>: ";
	if (t1 > t2)
	{
		cout << "Fisrt table has more columns than the second" << endl;
	}
	else
	{
		cout << "Fisrt table has less columns than the second" << endl;
	}

	//apel operator==
	cout << "Apel operator==: ";
	if (t1 == t3)
	{
		cout << "Tables have the same number of ids" << endl;
	}
	else
	{
		cout << "Tables don't have the same number of ids" << endl;
	}
	cout << endl;

	//apel operator>> si operator<<
	Table t5;
	cout << "Apel operator>>" << endl;
	cin >> t5;
	cout << endl << "Apel operator<<" << endl;
	cout << t5;


	/////TESTARE CLASA ROW/////
	cout << endl << "ROW" << endl;
	//apel constructor 1 cu parametri
	Row r1(10, "Students", columns2, 2);
	Row r3(11, "Students", columns3, 3);
	Row row(12, "Students", columns4, 4);

	//apel constructor 2 cu parametri
	Row r2("Professors");

	//apel constructor de copiere
	Row r4 = r1;

	//apel operator=
	Row r5;
	r5 = r3;

	//apel setteri si getteri
	Row r;
	r.setId(20);
	cout << "Apel getId: " << r.getId() << endl;
	r.setTableName("Prof");
	cout << "Apel getTableName: " << r.getTableName() << endl;
	r.setColumns(columns, 2);
	cout << "Apel getNbOfColumns: " << r.getNbOfColumns() << endl;
	cout << "Apel getColumns:" << endl;
	for (int i = 0; i < r.getNbOfColumns(); i++)
	{
		cout << "Column " << i + 1 << endl;
		cout << r.getColumns()[i] << " " << endl;
	}
	cout << endl;

	//apel operator[]
	r1[1] = col3;
	cout << "Apel operator[]: " << endl << r1[1] << endl;

	//apel operator+ 
	Row r7 = row + 2;
	cout << "Apel operator+: " << r7.getNbOfColumns() << endl;
	Row r8 = 3 + row;
	cout << "Apel comutativitate operator+: " << r8.getNbOfColumns() << endl;

	//apel operator cast
	char* tableName = r2;
	cout << "Apel operator cast: " << tableName << endl;

	//apel operator!
	cout << "Apel operator!: " << !r2 << endl;

	//apel operator>
	cout << "Apel operator>: ";
	if (r4 > r3)
	{
		cout << "First row has more columns than the second row" << endl;
	}
	else
	{
		cout << "First row has less columns than the second row" << endl;
	}

	//apel operator==
	cout << "Apel operator==: ";
	if (row == r2)
	{
		cout << "The rows are in the same table" << endl;
	}
	else
	{
		cout << "The rows aren't in the same table" << endl;
	}

	//apel operator<< si >>
	Row r6;
	cout << endl << "Apel operator citire: " << endl;
	cin >> r6;
	cout << endl << "Apel operator afisare: " << endl;
	cout << r6;


	/////TESTARE CLASA COMMAND/////
	cout << endl << "COMMAND" << endl;
	char* p1 = new char[strlen("param1") + 1];
	char* p2 = new char[strlen("param2") + 1];
	char* p3 = new char[strlen("param3") + 1];
	char* p4 = new char[strlen("param4") + 1];
	char* p5 = new char[strlen("param5") + 1];
	char* pm1 = new char[strlen("Table1") + 1];
	char* pm2 = new char[strlen("Table2") + 1];

	strcpy(p1, "param1");
	strcpy(p2, "param2");
	strcpy(p3, "param3");
	strcpy(p4, "param4");
	strcpy(p5, "param5");
	strcpy(pm1, "Table1");
	strcpy(pm2, "Table2");

	string parameters[] = { p1, p2, p3, p4 };
	string parameters2[] = { p1, p2, p3, p4, p5 };
	string parameters3[] = { pm1, pm2 };

	//apel constructor 1 cu parametri
	Command comm1("Data Manipulation Language", parameters, 4, 2);

	//apel constructor 2 cu parametri
	Command comm2(parameters2, 5);

	//apel constructor de copiere
	Command comm3 = comm1;

	//apel operator=
	Command comm4;
	comm4 = comm1;

	//apel setteri si getteri
	Command comm5;
	comm5.setType("DDL");
	cout << "Apel getType: " << comm5.getType() << endl;
	comm5.setParameters(parameters3, 2);
	cout << "Apel getNbOfParameters: " << comm5.getNbOfParameters() << endl;
	cout << "Apel getParameters: ";
	for (int i = 0; i < comm5.getNbOfParameters(); i++)
	{
		cout << comm5.getParameters()[i] << " ";
	}
	cout << endl;
	comm5.setNbOfCalls(2);
	cout << "Apel getNbOfCalls: " << comm5.getNbOfCalls() << endl;

	//apel operator[]
	comm5[1] = "parametru";
	cout << "Apel operator[]: " << comm5[1] << endl;

	//apel operator+
	Command comm7 = comm5 + 3;
	cout << "Apel operator+: " << comm7.getNbOfParameters() << endl;
	Command comm8 = 2 + comm7;
	cout << "Apel comutativitate operator+: " << comm8.getNbOfParameters() << endl;

	//apel operator++
	comm7 = ++comm1;
	cout << "Apel operator++ preincrementare: " << comm7.getNbOfCalls() << endl;
	comm8 = comm7++;
	cout << "Apel operator++ postincrementare: " << comm8.getNbOfCalls() << endl;

	//apel operator cast
	int nbOfParameters = (int)comm2;
	cout << "Apel operator cast: " << nbOfParameters << endl;

	//apel operator!
	bool beenCalled = !comm2;
	cout << "Apel operator!: " << beenCalled << endl;

	//apel operator>=
	cout << "Apel operator>=: ";
	if (comm1 >= comm4)
	{
		cout << "First command has more parameters than (or the same nb of parameters as) the second command" << endl;
	}
	else
	{
		cout << "First command has less parameters than the second command" << endl;
	}

	//apel operator==
	cout << "Apel operator==: ";
	if (comm1 == comm2)
	{
		cout << "First command has the same number of parameters as the second command" << endl;
	}
	else
	{
		cout << "First command hasn't the same number of parameters as the second command" << endl;
	}
	cout << endl;

	//apel operator<< si >>
	Command comm6;
	cout << "Apel operator>> " << endl;
	cin >> comm6;
	cout << "Apel operator<< " << endl;
	cout << comm6;



	/////TESTARE CLASA CONNECTION/////
	cout << endl << "CONNECTION" << endl;

	//apel constructor 1 cu paramateri
	int users[] = { 100,101,102,103 };
	int users2[] = { 100,101,102,103,104,105 };
	Connection con1(users, 4, "localhost", 1521);

	//apel constructor 2 cu parametri
	Connection con2("", 1502);

	//apel constructor de copiere
	Connection con3 = con1;

	//apel operator=
	Connection con4;
	con4 = con1;

	//apel setteri si getteri
	Connection con5;
	con5.setUserConnectedIds(users2, 6);
	cout << "Apel getNbOfConnections: " << con5.getNbOfConnections() << endl;
	cout << "Apel getUserConnectedIds: ";
	for (int i = 0; i < con5.getNbOfConnections(); i++)
	{
		cout << con5.getUserConnectedIds()[i] << " ";
	}
	cout << endl;
	con5.setPort(1234);
	cout << "Apel getPort: " << con5.getPort() << endl;
	cout << endl;

	//apel operator[]
	con5[4] = 110;
	cout << "Apel operator[]: " << con5[4] << endl;

	//apel operator+
	Connection con6 = con2 + 5;
	cout << "Apel operator+: " << con6.getPort() << endl;
	con6 = 10 + con2;
	cout << "Apel comutativitate operator+: " << con6.getPort() << endl;

	//apel operator++
	con6 = ++con5;
	cout << "Apel operator++ preincrementare: " << con6.getNbOfConnections() << endl;
	con6 = con1++;
	cout << "Apel operator++ postincrementare: " << con6.getNbOfConnections() << endl;

	//apel operator cast
	int con7 = con1;
	cout << "Apel operator cast: " << con7 << endl;

	//apel operator!
	bool haveUsersConnected = !con2;
	cout << "Apel operator!: " << haveUsersConnected << endl;

	//apel operator<
	cout << "Apel operator<: ";
	if (con1 < con5)
	{
		cout << "First connection has less connected users than the second" << endl;
	}
	else
	{
		cout << "First connection has more connected users than the second" << endl;
	}

	//apel operator==
	cout << "Apel operator==: ";
	if (con4 == con3)
	{
		cout << "Connections have the same number of connected users" << endl;
	}
	else
	{
		cout << "Connections don't have the same number of connected users" << endl;
	}
	cout << endl;

	//apel operator<< si >>
	Connection con;
	cout << "Apel operator>>" << endl;
	cin >> con;
	cout << "Apel operator<<" << endl;
	cout << con;


	// VERIFICARE SINTAXA SQL

	char query[1000];

	cout << "Introduceti una din urmatoare comenzi: CREATE/DISPLAY/DROP TABLE, CREATE/DROP INDEX" << endl;
	cout << "* Introduceti 'exit' pentru a iesi din program" << endl << endl;
	cin.getline(query, 1000);

	SqlCommand sqlCommand = SqlCommand();

	char* command = sqlCommand.detectCommand(query);

	bool correctQuery = false;

	while (strcmp(query, "exit") != 0)
	{

		if (command == nullptr)
		{
			cout << "Comanda introdusa nu este corecta." << endl;
		}

		else
		{
			if (strcmp(command, "create table") == 0)
			{
				correctQuery = sqlCommand.checkCreateTableQuery(query);
			}

			else if (strcmp(command, "display") == 0)
			{
				correctQuery = sqlCommand.checkDisplayTableQuery(query);
			}
			else if (strcmp(command, "drop table") == 0)
			{
				correctQuery = sqlCommand.checkDropTableQuery(query);
			}
			else if (strcmp(command, "create index") == 0)
			{
				correctQuery = sqlCommand.checkCreateIndexQuery(query);
			}
			else if (strcmp(command, "drop index") == 0)
			{
				correctQuery = sqlCommand.checkDropIndexQuery(query);
			}

			if (correctQuery == true) {

				cout << "Ati introdus comanda " << command << endl;
			}
			else
			{
				cout << "Comanda introdusa nu este corecta." << endl;
			}
		}

		cout << endl << "Introduceti una din urmatoare comenzi: CREATE/DISPLAY/DROP TABLE, CREATE/DROP INDEX";
		cout << " sau 'exit' pentru a iesi din program" << endl;
		cin.getline(query, 1000);

		command = sqlCommand.detectCommand(query);
		correctQuery = false;
	}
}