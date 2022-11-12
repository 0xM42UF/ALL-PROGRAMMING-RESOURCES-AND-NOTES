#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int code;
    int price;
    int quantity;
    string name;
    Item(int code, int price, int quantity, string name)
    {
        this->code = code;
        this->price = price;
        this->name = name;
        this->quantity = 10;
    }
};
class Restaurant
{
public:
    Item **items;
    int total_items;
    int total_tax;
    int ordered_number_of_items;
    Restaurant(int total_items)
    {
        this->items = new Item *[total_items];
        this->total_items = 0;
        this->total_tax = 0;
    }
    void add(Item *item)
    {
        this->items[this->total_items++] = item;
    }
    Item *get(int code)
    {
        for (int i = 0; i < total_items; i++)
        {
            if (items[i]->code == code)
            {
                return items[i];
            }
        }
        return NULL;
    }
    void print_title(string title, int tab, int tab2, int space)
    {
        cout << "\n";
        for (int i = 0; i < tab; i++)
            cout << "\t";
        cout << title << endl;
        for (int i = 0; i < tab2; i++)
            cout << "\t";
        for (int i = 0; i < space; i++)
            cout << " ";
        cout << "__________________\n\n";
    }
    void print_items(Item **all_items, int n, int is_all_items)
    {

        if (is_all_items)
        {
            cout << "Item Code\t"
                 << "Item Name\t\t"
                 << "Item Price\t\t"
                 << "Item Quantity\t"
                 << "Total Price\n";
            for (int i = 0; i < n; i++)
            {
                cout << all_items[i]->code << "\t\t"
                     << all_items[i]->name << "\t\t"
                     << all_items[i]->price << "\t\t"
                     << all_items[i]->quantity << "\t\t"
                     << all_items[i]->quantity * all_items[i]->price << endl;
            }
        }
        else
        {
            cout << "Item Code\t\t\t\t"
                 << "Item Name\t\t\t\t\t"
                 << "Item Price\n";
            for (int i = 0; i < n; i++)
            {
                cout << all_items[i]->code << "\t\t\t\t\t" << all_items[i]->name << "\t\t\t\t" << all_items[i]->price << endl;
            }
        }
    }
    void load_items(int total)
    {
        int price, code;
        string name;
        for (int i = 0; i < total; i++)
        {
            cin >> code;
            getline(cin, name);
            getline(cin, name);
            cin >> price;
            this->add(new Item(code, price, 10, name));
        }
    }
    void order_items()
    {
        cout << endl
             << endl;
        int tax = 5;
        int table, code, quantity = 0;
        int total_price = 0;
        Item *item;
        Item **ordered_items;
        cout << "Enter Table No : ";
        cin >> table;
        cout << "Enter Number of Items : ";
        cin >> this->ordered_number_of_items;
        ordered_items = new Item *[this->ordered_number_of_items];
        for (int i = 0; i < this->ordered_number_of_items; i++)
        {
            cout << "Enter Item " << i + 1 << " Code : ";
            cin >> code;
            item = this->get(code);
            while (!item)
            {
                cout << "Item Not Found! Enter the code again : ";
                cin >> code;
                item = this->get(code);
            }

            cout << "Enter Item" << i + 1 << "  Quantity : ";
            cin >> quantity;

            item->quantity = quantity;
            ordered_items[i] = item;
            total_price += (item->price * quantity);
        }
        cout << endl;
        this->print_title("BILL SUMMARY", 6, 5, 5);
        cout << "\nTable No. : " << table << endl;
        this->print_items(ordered_items, ordered_number_of_items, 1);
        cout << "TAX";
        for (int i = 0; i < 10; i++)
            cout << "\t";
        this->total_tax += (double(total_price) / 100) * tax;
        cout << this->total_tax << " Taka";
        cout << "\n";

        for (int i = 0; i < 92; i++)
            cout << "_";
        cout << "\n";
        cout << "NET TOTAL";
        for (int i = 0; i < 9; i++)
            cout << "\t";
        cout << this->total_tax + total_price << " Taka";
    }
};
int main()
{
    int total_items;
    cin >> total_items;
    Restaurant phitron = Restaurant(total_items);
    phitron.load_items(total_items);

    while (1)
    {
        phitron.print_title("MAKE BILL", 6, 5, 3);
        phitron.print_items(phitron.items, total_items, 0);
        phitron.order_items();
        cout << endl;
    }

    return 0;
}