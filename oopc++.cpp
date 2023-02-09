#include<iostream>
#include<string>
using namespace std;

class Phu_nu 
{
  public:
	 // khởi tạo constructor rỗng 
	 // constructor có tên trùng với Class
	 // Copy Constructor: gọi tự động ghi khởi tạo và gán
	 // Move Constructor: gọi tự động khi dùng toán tử move
	 Phu_nu() {
		  
	 }
	 // khởi tạo constructor có value
	 // default parameter 
	 // Dùng danh sách khỏi tạo trong  c++ thay vì gán khởi tạo mặc định.
	 // ht = "Maria Ozawa" : copy chuỗi kí tự &ht "Ozawa:" sử dụng luôn chuỗi kí tự
	 Phu_nu(const string& ht, int t, bool z = true) : ho_ten(ht), tuoi(t), con_zin(z)
	 {
		 //ho_ten = ht;
		 //con_zin = z;
	 }
	 ~Phu_nu() {
		 cout << "Chia tay " << ho_ten << endl;
	 }

	 void trang_diem() {

	 }
	 virtual string choi_nhac_cu(string nhac_cu) {
		 return "AAAAAAA";
	 }
	 void va_zin() {
		 if (tuoi < 25) {
			 con_zin = true;
		 }
	 }
	 void show_hang() {
		 cout << ho_ten << " " << (con_zin ? "con zin" : "mat zin") << endl;
	 }
  // Dữ liệu được phép truy cập từ bên ngoài class
  protected:
	  bool con_zin;
	  string ho_ten;
	  int tuoi;
  // chỉ bên trong class được sử dụng
  // bien protected thi  class con moi lay duoc 
};
//extends;
class Gai_ngoan : public Phu_nu
{
    public:
		// Derived class
		Gai_ngoan(const string& ht, int t, bool z = true) :  Phu_nu(ht,t,z)
		{
			//ho_ten = ht;
			//con_zin = z;
		}
		string choi_nhac_cu(string nhac_cu) {
			return "0000000000";
		}
		void noi_tro() {
			cout << ho_ten << " " << "dang lam noi  tro" << endl;
		}
};
//extends;
class Gai_Hu : public Phu_nu 
{
public:
	// Derived class
	Gai_Hu(const string& ht, int t, bool z = true) : Phu_nu(ht, t, z)
	{
		//ho_ten = ht;
		//con_zin = z;
	}
	string choi_nhac_cu(string nhac_cu) {
		return "UUUUUUUUU";
	}
	void di_bar() {

	}
	
};
// dimond inheritance
class Banh_Beo : public Gai_ngoan, public Gai_Hu {


};
// multi-level inheritance (Ke thua da muc)
class Gai_Di_Tour : public Gai_Hu {

};
// interface

// file scope
class Dan_ong {

};

int main() {       
	// function scope
	// Phu_nu thao;
	Phu_nu *maria_ozawa = new Gai_ngoan("Maria ozawa",22,false);
	//maria_ozawa->ho_ten = "Maria ozawa";
	cout << maria_ozawa->choi_nhac_cu("ken") << endl;
	//maria_ozawa->va_zin();
	//maria_ozawa->show_hang();
	//delete maria_ozawa;
	//Dan_ong *vu = new Dan_ong;
	return 0;
}