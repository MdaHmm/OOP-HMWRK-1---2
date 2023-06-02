#include <iostream>
#include <string>
#include <vector>


class Subscriber {
private:
    std::string _fio;
    std::string _home_phone;
    std::string _work_phone;
    std::string _mobile_phone;
    std::string _more_info;
public:
    Subscriber() {
        std::cout << "Введите фамилию имя и отчество абонента -> ";
        std::string fio;
        std::getline(std::cin, fio);
        _fio = fio;
        std::cout << "Введите номер домашнего телефона абонента -> ";
        std::string home_phone;
        std::getline(std::cin, home_phone);
        _home_phone = home_phone;
        std::cout << "Введите номер рабочего телефона абонента -> ";
        std::string work_phone;
        std::getline(std::cin, work_phone);
        _work_phone = work_phone;
        std::cout << "Введите номер мобильного телефона абонента -> ";
        std::string mobile_phone;
        std::getline(std::cin, mobile_phone);
        _mobile_phone = mobile_phone;
        std::cout << "Укажите дополнительную информацию об абоненте -> ";
        std::string more_info;
        std::getline(std::cin, more_info);
        _more_info = more_info;
    }


    void ShowAllData() {
        std::cout << "Абонент: " << _fio << '\n';
        std::cout << "Мобильный телефон: " << _mobile_phone << '\n';
        std::cout << "Рабочий телефон: " << _work_phone << '\n';
        std::cout << "Домашний телефон: " << _home_phone << '\n';
        std::cout << "Дополнительная информация: " << _more_info << "\n\n";
    }

    std::string GetName() {
        return _fio;
    }

    ~Subscriber() {
        std::cout << "Абонент удален." << '\n';
    }
};

class PhoneBook {
private:
    std::vector <Subscriber*>_subscribers;
public:

    void AddSub(Subscriber* subscriber) {
        _subscribers.push_back(subscriber);
    }

    void ShowSub() {
        for (const auto& it : _subscribers)
            it->ShowAllData();
    }

    void RemoveSub(const std::string& fio)
    {
        for (auto it = _subscribers.begin(); it != _subscribers.end(); ++it) {
            if ((*it)->GetName() == fio) { // нужно пояснение
                _subscribers.erase(it);
                return;
            }
        }
    }

    ~PhoneBook() {
        std::cout << "Книга удалена";
    }


};


int main() {
    setlocale(LC_ALL, "Russian");

    unsigned int n;
    std::string del_fio;
    std::string choice;
    std::cout << "Укажите количество записей, которые вы планируете внести в телефонную книгу ->\n";
    std::cin >> n;
    std::cin.ignore();

    PhoneBook* phb = new PhoneBook();
    for (int i{}; i < n; i++) {
        Subscriber* sub = new Subscriber();
        phb->AddSub(sub);
        std::cout << "______________________\n\nАбонент " << sub->GetName() << " добавлен.\n_____________________\n\n";
    }

    n = 1;

    while (choice != "4") {
        std::cout << "Выберите действие:\n";
        std::cout << "1 - Добавить абонента.\n";
        std::cout << "2 - Удалить абонента.\n";
        std::cout << "3 - Вывести список всех абонентов.\n";
        std::cout << "4 - Выход.\n";

        std::cin >> choice;
        std::cin.ignore();

        if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
            std::cout << "Ошибка ввода.\n\n";
        else
            if (choice == "1")
                for (int i{}; i < n; i++) {
                    Subscriber* sub = new Subscriber();
                    phb->AddSub(sub);
                    std::cout << "______________________\n\nАбонент " << sub->GetName() << " добавлен.\n_____________________\n\n";
                }
        if (choice == "2") {
            std::cout << "\nВыберите абонента из списка и укажите его ФИО.\n";
            phb->ShowSub(); // Пока реализовал так, потому что прога не видит здесь вектор...
            std::cout << "\nВвод ->";
            std::getline(std::cin, del_fio);
            phb->RemoveSub(del_fio);
            std::cout << "\nАбонент " << del_fio << " удален.";
        }
        if (choice == "3")
            phb->ShowSub();


    };

    delete(phb);




    return 0;
}
