#include <iostream>
using namespace std;
class Ingredients
{
public:
    string ing_name;
    Ingredients *next;

    Ingredients()
    {
        next = NULL;
    }

    Ingredients(string name)
    {
        ing_name = name;
        next = NULL;
    }
};
class Dish
{
public:
    Ingredients *head;
    string dish_name;
    Dish *right;
    Dish *left;

    Dish()
    {
        head = NULL;
        right = NULL;
        left = NULL;
    }

    Dish(string name)
    {
        head = NULL;
        dish_name = name;
        right = NULL;
        left = NULL;
    }
};

class Menu
{
    Dish *root;

public:
    Menu()
    {
        root = NULL;
    }
    void create();
    void addDish(string name);
    void showDish();
    void showDishIng();
    void inorder(Dish *t);
};

void Menu::create()
{
    string dn;
    while (true)
    {
        cout << "Enter dishes or -1 to stop : " << endl;
        cin >> dn;
        if (dn == "-1")
        {
            break;
        }

        addDish(dn);
    }
}

void Menu::addDish(string name)
{
    Dish *t;
    Dish *q;
    t = root;
    q = t;

    if (t == NULL)
    {
        t = new Dish(name);
    }

    else
    {
        while (t != NULL)
        {
            q = t;
            if (name > t->dish_name)
            {
                t = t->right;
            }
            else if (name < t->dish_name)
            {
                t = t->left;
            }
            else
            {
                cout << "Duplicate entery not allowed!!!!!!" << endl;
                cout << "Enter again" << endl;
                return;
            }
        }

        if (name > q->dish_name)
        {
            q->right = new Dish(name);
        }
        else
        {
            q->left = new Dish(name);
        }
    }
}

void Menu::showDish()
{
    Dish *t;
    t = root;

    inorder(t);
}

void Menu::inorder(Dish *t)
{
    if (t)
    {
        inorder(t->left);
        cout << t->dish_name << "   ";
        inorder(t->right);
    }
}

int main()
{
    Menu m;
    m.create();
    m.showDish();
    // m.showDishIng();

    return 0;
}