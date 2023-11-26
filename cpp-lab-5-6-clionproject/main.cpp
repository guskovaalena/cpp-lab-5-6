#include <iostream>
using namespace std;

class language {

private:
    string name;
    int wordsAmount;
    int complexity;
    long int nativeAmount;

public:

    //конструктор без параметров
    language(){
        name = "Неизвестный";
        wordsAmount = 0;
        complexity = 1;
        nativeAmount = 0;
    }

    //конструктор с параметрами
    language(string nameValue, int wordsAmountValue, int ccomplexityValue, long int nativeAmountValue){
        if (ccomplexityValue >= 1 && ccomplexityValue <= 5){
            name = nameValue;
            wordsAmount = wordsAmountValue;
            complexity = ccomplexityValue;
            nativeAmount = nativeAmountValue;
        }
        else {
            cout<<"Некорректное значение поля сложность изучения"<<endl;
            exit(EXIT_FAILURE);
        }
    }

    //конструктор копирования
    language(const language &other){
        this->name = other.name;
        this->wordsAmount = other.wordsAmount;
        this->complexity = other.complexity;
        this->nativeAmount = other.nativeAmount;
    }

    //получение значений каждого поля
    string getName(){
        return name;
    }
    int getWordsAmount(){
        return wordsAmount;
    }
    int getComlexity(){
        return complexity;
    }
    long int getNativeAmount(){
        return nativeAmount;
    }

    //редактирование каждого поля
    void setName(string nameValue){
        name = nameValue;
    }
    void setWordsAmount(int wordsAmountValue){
        wordsAmount = wordsAmountValue;
    }
    void setComplexity(int complexityValue){
        if (complexityValue >= 1 && complexityValue <= 5){
            complexity = complexityValue;
        }
        else {
            cout<<"Некорректное значение поля сложность изучения"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    void setNativeAmount (long int nativeAmountValue){
        nativeAmount = nativeAmountValue;
    }

    //вывод на экран каждого поля
    void printName(){
        cout<<name<<" язык"<<endl;
    }
    void printWordsAmount(){
        cout<<"Количество слов: "<<wordsAmount<<endl;
    }
    void printComplexity(){
        cout<<"Сложность изучения: "<<complexity<<" из 5"<<endl;
    }
    void printNativeAmount(){
        cout<<"Количество носителей: "<<nativeAmount<<" человек"<<endl;
    }

    //вывод на экран полной информации о языке
    void printAll(){
        cout<<name<<" язык"<<endl;
        cout<<"Количество слов: "<<wordsAmount<<endl;
        cout<<"Сложность изучения: "<<complexity<<" из 5"<<endl;
        cout<<"Количество носителей: "<<nativeAmount<<" человек"<<endl;
    }

    static void bubbleSortByWordsAmount(language* languages, int n){
        bool swapped;
        for (int i = 0; i < n; i++){
            swapped = false;
            for (int j = 0; j < n - i - 1; j++){
                if (languages[j].getWordsAmount() > languages[j+1].getWordsAmount()){
                    swap(languages[j], languages[j+1]);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }

    //список наименований мертвых языков, отсортированный по количеству слов
    static string* deadLanguagesList(language* languages, int n){
        language::bubbleSortByWordsAmount(languages, n);
        int size = 0;
        for (int i = 0; i < n; i++){
            if (languages[i].getNativeAmount() == 0){
                size++;
            }
        }
        string* list = new string[size];
        int k = 0;
        for (int i = 0; i < n; i++){
            if (languages[i].getNativeAmount() == 0){
                list[k] = languages[i].getName();
                k++;
            }
        }
        return list;
    }

    static long int averageNativeAmount(language* languages, int n){
        long int sum = 0;
        for (int i = 0; i < n; i++){
            sum += languages[i].getNativeAmount();
        }
        return sum / n;
    }

    //среднее личество слов среди языков сложности N
    static long int averageWordsAmountAmongGivenComplexity(language* languages, int n, int N){
        long int sum = 0;
        int num = 0;
        for (int i = 0; i < n; i++){
            if (languages[i].getComlexity() == N){
                sum += languages[i].getWordsAmount();
                num++;
            }
        }
        return sum / num;
    }

    ~language()= default;

};

int main(){

    setlocale(LC_ALL, "ru");
    //лабораторная 5

    //конструктор без параметров
    language firstLanguage;
    //функции редактирования полей
    firstLanguage.setName("Русский");
    firstLanguage.setWordsAmount(500000);
    firstLanguage.setComplexity(4);
    firstLanguage.setNativeAmount(154000000);

    //конструктор с параметрами
    language secondLanguage("Английский", 273000, 2, 379000000);

    //функции вывода на экран каждого поля
    firstLanguage.printName();
    firstLanguage.printWordsAmount();
    firstLanguage.printComplexity();
    firstLanguage.printNativeAmount();
    cout<<endl;

    //функция выводв на экран полной информации о языке
    secondLanguage.printAll();
    cout<<endl;

    //конструктор копирования
    language thirdLanguage(firstLanguage);
    thirdLanguage.printAll();
    cout<<endl;


    //лабораторная 6

    int n;
    cout<<"Введите количество языков:"<<endl;
    cin>>n;

    language languages[n];

    for (int i = 0; i < n; i++){
        string nameValue;
        cout<<"Введите наименование языка "<<i+1<<"-го языка:"<<endl;
        cin>>nameValue;
        languages[i].setName(nameValue);

        int wordsAmoutValue;
        cout<<"Введите количество слов в "<<i+1<<"-ом языке:"<<endl;
        cin>>wordsAmoutValue;
        languages[i].setWordsAmount(wordsAmoutValue);

        int complexityValue;
        cout<<"Введите сложность "<<i+1<<"-го языка от 1 (очень легкий) до 5 (очень тяжелый):"<<endl;
        cin>>complexityValue;
        languages[i].setComplexity(complexityValue);

        long int nativeAmountValue;
        cout<<"Введите количество носителей "<<i+1<<"-го языка"<<endl;
        cin>>nativeAmountValue;
        languages[i].setNativeAmount(nativeAmountValue);

        cout<<endl;
    }

    cout<<"Введены следующие языки:"<<endl;
    for (int i = 0; i < n; i++){
        cout<<"№"<<i+1<<' ';
        languages[i].printAll();
        cout<<endl;
    }

    //№1 список мертвых языков, отсортированный по количеству слов
    cout<<"Список наименований мертвых языков, отсортированный по возрастанию количества слов:"<<endl;
    for (int i = 0; i < n; i++){
        cout<<i+1<<". "<<language::deadLanguagesList(languages, n)[i]<<endl;
    }

    cout<<endl;

    //№2 Среднее количество носителей среди всех языков
    cout<<"Среднее количество носителей среди всех языков: "<<language::averageNativeAmount(languages, n)<<endl;

    cout<<endl;

    //№3 среднее количество слов среди языков сложности N
    int N;
    cout<<"Введите сложность изучения языка N от 1 (очень легкий) до 5 (очень тяжелый):"<<endl;
    cin>>N;
    if (N >= 1 && N<= 5){
        cout<<"Среднее количество слов среди языков сложности "<<N<<": "<<language::averageWordsAmountAmongGivenComplexity(languages, n, N)<<endl;
    }
    else {
        cout<<"Некорректный ввод значения сложности языка"<<endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}