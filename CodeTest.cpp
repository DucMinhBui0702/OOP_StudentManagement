#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
void sortArray(vector<int> &num)
{
	sort(num.begin(), num.end());
}
int main(void)
{
	int n;
	int x;
	vector<int> arr;
	cout << "Nhap so luong so nguyen: " ;
	cin >> n;
	cout << "Nhap cac so: " << endl;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sortArray(arr);
	cout << "Nhap so muon tim: " ;
	cin >> x;
	cin.ignore();
	if(binary_search(arr.begin(), arr.end(), x))
	{
		auto loc = lower_bound(arr.begin(), arr.end(), x);
		cout << "So " << x << "Da tim thay, vi tri: " << distance(arr.begin(), loc) << endl;
	}
	else cout << "Khong tim thay so " << x << endl <<endl;
	//BONUS
	int sdt;
	cout << "Nhap so luong sdt ban muon them: ";
	cin >> sdt;
	cin.ignore();
	string tempname, tempsdt;
	map<string, string> dial;
	cout << "Nhap theo cu phap: Ten + SDT" << endl << endl;
	for(int j = 0; j < sdt; j++)
	{
		getline(cin, tempname);
		getline(cin, tempsdt);
		dial.insert({tempname, tempsdt});
		cout << endl;
	}
	cout << endl << "Danh sach SDT cua ban: " << endl;
	for(auto x: dial)
	{
		cout << x.first << " - " << x.second << endl;
	}
	string name;
	cout << "Nhap ten nguoi ban muon tim sdt: ";
	getline(cin ,name);
	auto ten = dial.find(name);
	if(ten != dial.end())
	{
		cout << "SDT cua nguoi ban muon tim la: " << ten->second;
	}
	else cout << "khong tim thay ten nguoi dung.";
 return 0;
}
