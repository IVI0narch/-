#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class matrix {
public:

    matrix(vector<double> tmp)
    {
        if (sqrt(tmp.size()) - ceil(sqrt(tmp.size())) == 0)
        {
            size = (int)sqrt(tmp.size());
            for (int i = 0; i < size; i++)
            {
                content.push_back({});
                for (int j = 0; j < size; j++)
                {
                    content[i].push_back(tmp[(i * size) + j]);
                }
            }
        }
        else
        {
            size = 0;
            cout << "Wrong matrix dimention.";
        }

    }

    ~matrix()
    {
    }

    void print()
    {
        for (int i = 0; i < content.size() - 1; i++)
        {
            for (int j = 0; j < content[i].size(); j++)
            {
                cout << content[i][j] << ' ';
            }
            cout << '\n';
        }

        for (int j = 0; j < content[content.size() - 1].size(); j++)
        {
            cout << content[content.size() - 1][j] << ' ';
        }
    }


    friend matrix operator *(matrix a, matrix b)
    {
        if (a.size == b.size)
        {
            vector<double> Multipl_vec;
            for (int i = 0; i < a.size; i++)
            {
                for (int j = 0; j < a.size; j++)
                {
                    double sum = 0;
                    for (int t = 0; t < a.size; t++)
                    {
                        sum += a.content[i][t] * b.content[t][j];
                    }
                    Multipl_vec.push_back(sum);
                }
            }
            matrix Multipl(Multipl_vec);
            return Multipl;
        }
        else
        {
            return a;
            cout << "Wrong matrix dimention.";
        }
    }

private:
    vector<vector<double>> content;
    int size;
};


int main()
{
    int N;
    cin >> N;
    vector<double> tmp_1;
    vector<double> tmp_2;
    for (int i = 0; i < N * N; i++)
    {
        float x;
        cin >> x;
        tmp_1.push_back(x);
    }

    for (int i = 0; i < N * N; i++)
    {
        float x;
        cin >> x;
        tmp_2.push_back(x);
    }

    matrix m1(tmp_1);
    matrix m2(tmp_2);
    (m1 * m2).print();
}
