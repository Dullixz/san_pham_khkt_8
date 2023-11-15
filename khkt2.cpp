#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
string answer;
bool isFloatingPoint(const std::string &input)
{
    std::istringstream ss(input);
    float f;
    ss >> std::noskipws >> f; // try to read float number

    // Check the entire string was consumed and if the next character is whitespace or EOF
    return ss.eof() && !ss.fail();
}
bool isChinhPhuong(int number)
{
    int squareRoot = sqrt(number);
    return squareRoot * squareRoot == number;
}
bool isPerfectNumber(int number)
{
    int sum = 1; // Bắt đầu với 1 vì mỗi số tự nhiên đều chia hết cho 1
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
            if (i != number / i)
            {
                sum += number / i;
            }
        }
    }
    return sum == number;
}
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}
double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

// Function to check if a number is prime
bool sPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void phanTichThanhThuaSoNguyenTo(int n)
{
    cout << "Cac thua so nguyen to cua " << n << " la: ";

    // Kiem tra cac thua so nguyen to bat dau tu 2
    for (int i = 2; i <= n; ++i)
    {
        // Kiem tra i co phai la thua so nguyen to cua n hay khong
        while (n % i == 0)
        {
            // In ra thua so nguyen to i va chia n cho i
            cout << i << " ";
            n = n / i;
        }
    }

    cout << endl;
}
bool isPalindrome(int num)
{
    int originalNum = num;
    int reverseNum = 0;
    while (num > 0)
    {
        reverseNum = reverseNum * 10 + num % 10;
        num /= 10;
    }
    return originalNum == reverseNum;
}

// main

int main()
{

    std::cout << "***********************************************\n";
    std::cout << "**          NHUNG LUA CHON SAN CO            **\n";
    std::cout << "**                                           **\n";
    std::cout << "******************************************************************************************\n";
    std::cout << "**                                           **                                         **\n";
    std::cout << "**    1. Chuyen doi do C sang do F           **    LUU Y: DAU ',' TRONG SO THAP PHAN    **\n";
    std::cout << "**    2. Chuyen doi do F sang do C           **           DUOC VIET LA '.'              **\n";
    std::cout << "**    3. Tim GCD (Uoc so chung lon nhat)     **           DAU AM VIET LA '-'            **\n";
    std::cout << "**    4. Tim LCM (Boi chung nho nhat)        **      NHAN PHIM 0 (SO KHONG) DE THOAT    **\n";
    std::cout << "**    5. Tim cac so nguyen to                **                                         **\n";
    std::cout << "**    6. Kiem tra so nguyen to               *********************************************\n";
    std::cout << "**    7. Phan tich mot so ra thua so         **\n";
    std::cout << "**       nguyen to                           **\n";
    std::cout << "**    8. Kiem tra so Palindrom               **\n";
    std::cout << "**    9. Tim uoc cua mot so                  **\n";
    std::cout << "**    10. Tim boi cua mot so                 **\n";
    std::cout << "**    11. Tim so chinh phuong                **\n";
    std::cout << "**    12. Kiem tra so chinh phuong           **\n";
    std::cout << "**    13. Tim tong day so co quy luat        **\n";
    std::cout << "**         (dung cho day so tu nhien)        **\n";
    std::cout << "**    14. Tim tong day so Fibonacci          **\n";
    std::cout << "**    15. Kiem tra so hoan hao               **\n";
    std::cout << "**                0.EXIT                     **\n";
    std::cout << "**                                           **\n";
    std::cout << "***********************************************\n";
    std::cout << "**          NHAP LUA CHON CUA BAN!           **\n";
    std::cout << "**                                           **\n";
    std::cout << "***********************************************\n";
    std::cout << "Lua chon cua ban la: ";
    std::cin >> answer;
    bool isNumber = true;
    for (int i = 0; i < answer.length(); i++)
    {
        if (!isdigit(answer[i]))
        {
            isNumber = false;
            cout << "Ban da nhap sai\n";
            break;
        }
    }

    if (isNumber)
    {
        char *endPtr;
        long long number = std::strtoll(answer.c_str(), &endPtr, 10);
        if (number == 1)
        {
                string doCelsius;
                double doFahrenheit;

                cout << "Nhap nhiet do Celsius: ";
                cin >> doCelsius;

                // Kiểm tra xem doCelsius có phải là số thực không
                stringstream ss(doCelsius);
                double doC;
                if (!(ss >> doC))
                {
                    cout << "Loi! Ban da nhap mot ky tu khong phai la so thuc." << endl;
                    return 1;
                }

                // Thực hiện chuyển đổi độ Celsius sang độ Fahrenheit
                doFahrenheit = (doC * 9.0 / 5.0) + 32.0;

                // Hiển thị kết quả với độ chính xác 2 số thập phân
                cout << fixed << setprecision(2);
                cout << doC << " do Celsius tuong duong voi " << doFahrenheit << " do Fahrenheit." << endl;
            }

            if (number == 2)
            {
                std::string input;
                double fahrenheit;

                std::cout << "Nhap do Fahrenheit: ";
                cin >> input;
                std::getline(std::cin, input);

                std::stringstream ss(input);

                if (ss >> fahrenheit)
                {
                    double celsius = fahrenheitToCelsius(fahrenheit);
                    std::cout << "Do Celsius tuong ung: " << celsius << std::endl;
                }
                else
                {
                    std::cout << "Dau vao khong hop le." << std::endl;
                }
            }
            if (number == 3)
            {
                string dapan1, dapan2;
                cout << "Nhap so thu nhat: ";
                cin >> dapan1;
                bool isNumber = true;
                for (int i = 0; i < dapan1.length(); i++)
                {
                    if (!isdigit(dapan1[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long num1 = std::strtoll(dapan1.c_str(), &endPtr, 10);

                    cout << "Nhap so thu hai: ";
                    cin >> dapan2;
                    bool isNumber = true;
                    for (int i = 0; i < dapan2.length(); i++)
                    {
                        if (!isdigit(dapan2[i]))
                        {
                            isNumber = false;
                            cout << "Ban da nhap sai";

                            break;
                        }
                    }

                    if (isNumber)
                    {
                        char *endPtr;
                        long long num2 = std::strtoll(dapan2.c_str(), &endPtr, 10);

                        cout << "Uoc chung lon nhat: " << gcd(num1, num2) << endl;
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 4)
            {
                string dapan1, dapan2;
                cout << "Nhap so thu nhat: ";
                cin >> dapan1;
                bool isNumber = true;
                for (int i = 0; i < dapan1.length(); i++)
                {
                    if (!isdigit(dapan1[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long a = std::strtoll(dapan1.c_str(), &endPtr, 10);

                    cout << "Nhap so thu hai: ";
                    cin >> dapan2;
                    bool isNumber = true;
                    for (int i = 0; i < dapan2.length(); i++)
                    {
                        if (!isdigit(dapan2[i]))
                        {
                            isNumber = false;
                            cout << "Ban da nhap sai";

                            break;
                        }
                    }

                    if (isNumber)
                    {
                        char *endPtr;
                        long long b = std::strtoll(dapan2.c_str(), &endPtr, 10);

                        cout << "Boi chung nho nhat: " << a * b << endl;
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 5)
            {
                string dapan;
                cout << "Nhap mot so :";
                cin >> dapan;
                bool isNumber = true;
                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long v = std::strtoll(dapan.c_str(), &endPtr, 10);

                    cout << "Danh sach cac so nguyen to tu 1 den " << v << " la:" << endl;
                    for (int i = 2; i < v; i++)
                    {
                        bool prime = true;
                        for (int j = 2; j * j <= i; j++)
                        {
                            if (i % j == 0)
                            {
                                prime = false;
                                break;
                            }
                        }
                        if (prime)
                            cout << i << " ";
                    }
                    cout << "\n";
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 6)
            {
                string dapan;
                cout << "Nhap so muon kiem tra: ";
                cin >> dapan;
                bool isNumber = true;

                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long num = std::strtoll(dapan.c_str(), &endPtr, 10);

                    if (isPrime(num))
                    {
                        cout << dapan << " la so nguyen to" << endl;
                    }
                    else
                    {
                        cout << dapan << " khong phai la so nguyen to" << endl;
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 7)
            {
                string dapan;
                cout << "Nhap vao mot so nguyen duong: ";
                cin >> dapan;
                bool isNumber = true;

                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long num = std::strtoll(dapan.c_str(), &endPtr, 10);

                    // Goi ham phan tich thanh thua so nguyen to
                    phanTichThanhThuaSoNguyenTo(num);
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 8)
            {
                string dapan;
                cout << "Nhap so muon kiem tra: ";
                cin >> dapan;
                bool isNumber = true;

                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long num = std::strtoll(dapan.c_str(), &endPtr, 10);
                    if (isPalindrome(num))
                    {
                        cout << num << " la so palindrome." << endl;
                    }
                    else
                    {
                        cout << num << " khong phai la so palindrome." << endl;
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 9)
            {
                string dapan;
                std::cout << "Nhap so can tim uoc: ";
                std::cin >> dapan;
                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long y = std::strtoll(dapan.c_str(), &endPtr, 10);

                    std::cout << "Tat ca cac uoc cua so " << y << " la: ";
                    for (int i = 1; i <= y; i++)
                    {
                        if (y % i == 0)
                        {
                            std::cout << i << " ";
                        }
                    }
                    std::cout << "\n";
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 10)
            {
                string dapan1;
                int m;
                string dapan2;
                int b;
                std::cout << "Nhap so muon tim boi: ";
                std::cin >> dapan1;
                bool isNumber = true;

                for (int i = 0; i < dapan1.length(); i++)
                {
                    if (!isdigit(dapan1[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long x = std::strtoll(dapan1.c_str(), &endPtr, 10);

                    std::cout << "Ban muon tim bao nhieu boi cua " << dapan1 << ": ";
                    std::cin >> dapan2;
                    bool isNumber = true;

                    for (int i = 0; i < dapan2.length(); i++)
                    {
                        if (!isdigit(dapan2[i]))
                        {
                            isNumber = false;
                            cout << "Ban da nhap sai";

                            break;
                        }
                    }

                    if (isNumber)
                    {
                        char *endPtr;
                        long long i = std::strtoll(dapan2.c_str(), &endPtr, 10);

                        for (size_t m = 1; m <= i; m++)
                        {
                            b = x * m;
                            std::cout << b << " ";
                        }
                        cout << "\n";
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 11)
            {
                string dapan;
                cout << "Nhap so n: ";
                cin >> dapan;
                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long n = std::strtoll(dapan.c_str(), &endPtr, 10);

                    cout << "Cac so chinh phuong tu 1 den " << n << " la: ";
                    for (int i = 1; i <= n; ++i)
                    {
                        if (isChinhPhuong(i))
                        {
                            cout << i << " ";
                        }
                    }

                    cout << endl;
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 12)
            {
                string dapan;
                int b;
                std::cout
                    << "Nhap so chinh phuong can kiem tra: ";
                std::cin >> dapan;
                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long x = std::strtoll(dapan.c_str(), &endPtr, 10);

                    for (size_t a = 0; a < x; a++)
                    {
                        b = a * a;
                        if (b == x)
                        {
                            std::cout << x << " La so chinh phuong!\n";
                            break;
                        }
                    }
                    if (b != x)
                    {
                        std::cout << x << " Khong phai la so chinh phuong\n";
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 13)
            {
                string dapan1;
                cout << "Nhap so cuoi: ";
                cin >> dapan1;
                bool isNumber = true;

                for (int i = 0; i < dapan1.length(); i++)
                {
                    if (!isdigit(dapan1[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long n = std::strtoll(dapan1.c_str(), &endPtr, 10);

                    string dapan2;
                    cout << "Nhap so dau: ";
                    cin >> dapan2;
                    bool isNumber = true;

                    for (int i = 0; i < dapan2.length(); i++)
                    {
                        if (!isdigit(dapan2[i]))
                        {
                            isNumber = false;
                            cout << "Ban da nhap sai";

                            break;
                        }
                    }

                    if (isNumber)
                    {
                        char *endPtr;
                        long long b = std::strtoll(dapan2.c_str(), &endPtr, 10);

                        string dapan3;
                        cout << "Nhap khoang cach: ";
                        cin >> dapan3;
                        bool isNumber = true;

                        for (int i = 0; i < dapan3.length(); i++)
                        {
                            if (!isdigit(dapan3[i]))
                            {
                                isNumber = false;
                                cout << "Ban da nhap sai";

                                break;
                            }
                        }

                        if (isNumber)
                        {
                            char *endPtr;
                            long long a = std::strtoll(dapan3.c_str(), &endPtr, 10);
                            if ((n - b) % a == 0)
                            {
                                // Tính tổng các số từ 1 đến n
                                int tong = ((b + n) * ((n - b) / a + 1) / 2);

                                cout << "Tong cac so tu " << b << " den " << n << " voi khoang cach " << a << " la: " << tong << endl;
                            }
                            else
                            {
                                cout << "Khong tim duoc quy luat\n";
                            }
                        }
                    }
                }
                if (isNumber = false)
                {
                nodouble:
                    cout << "Ban da nhap sai\n";
                }
            }

            if (number == 14)
            {
                int t1 = 0, t2 = 1, nextTerm = 0, sum = 0;
                string dapan;
                cout << "Nhap so phan tu: ";
                cin >> dapan;
                bool isNumber = true;

                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long n = std::strtoll(dapan.c_str(), &endPtr, 10);

                    cout << "Day so Fibonacci: ";

                    for (int i = 1; i <= n; ++i)
                    {
                        if (i == 1)
                        {
                            cout << t1 << " ";
                            sum += t1;
                            continue;
                        }
                        if (i == 2)
                        {
                            cout << t2 << " ";
                            sum += t2;
                            continue;
                        }
                        nextTerm = t1 + t2;
                        t1 = t2;
                        t2 = nextTerm;
                        sum += nextTerm;
                        cout << nextTerm << " ";
                    }
                    cout << endl;

                    cout << "Tong cac phan tu trong day so Fibonacci la: " << sum << endl;
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 15)
            {
                string dapan;
                cout << "Nhap mot so: ";
                cin >> dapan;
                bool isNumber = true;

                for (int i = 0; i < dapan.length(); i++)
                {
                    if (!isdigit(dapan[i]))
                    {
                        isNumber = false;
                        cout << "Ban da nhap sai";

                        break;
                    }
                }

                if (isNumber)
                {
                    char *endPtr;
                    long long number = std::strtoll(dapan.c_str(), &endPtr, 10);

                    if (isPerfectNumber(number))
                    {
                        cout << number << " la so hoan hao." << endl;
                    }
                    else
                    {
                        cout << number << " khong phai la so hoan hao." << endl;
                    }
                }
                if (isNumber = false)
                {
                    cout << "Ban da nhap sai\n";
                }
            }
            if (number == 0)
            {
                exit(0);
            }
            if (number > 17)
            {
                std::cout << "Khong co yeu cau nay!\n";
            }
        }

        if (isNumber = false)
        {
            cout << "Ban da nhap sai\n";
        }

    a:
        std::cout << "Ban co muon tiep tuc khong?"
                  << "\n";
        std::cout << "'y': co ; 'n': khong\n";
        char q;
        std::cin >> q;
        switch (q)
        {
        case 'y':
        case 'Y':
            system("cls");
            return main();
            break;
        case 'n':
        case 'N':
            std::cout << "Tam biet!";
            break;
        default:
            std::cout << "Khong co yeu cau\nMoi ban nhap lai!\n";
            goto a;
        }
    }
