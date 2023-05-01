#include <bits/stdc++.h>
using namespace std;
// HocSinh - Begin
struct HocSinh
{
  int maHS;
  char lop[20], hoten[50], ngaySinh[20], gtHS[10], diaChi[50];
};
struct NodeHS
{
  HocSinh infor;
  struct NodeHS *next;
};
struct StackHS
{
  NodeHS *top;
};
void initHS(StackHS &HS)
{
  HS.top = NULL;
}
NodeHS *getNodeHS(HocSinh hs)
{
  NodeHS *p = new NodeHS;
  if (p == NULL)
  {
    cout << "\nKhong du bo nho!";
    return 0;
  }
  p->infor = hs;
  p->next = NULL;
  return p;
}
int isEmptyHS(StackHS HS)
{
  if (HS.top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void PushHS(StackHS &HS, NodeHS *p)
{
  if (HS.top == NULL)
  {
    HS.top = p;
  }
  else
  {
    p->next = HS.top;
    HS.top = p;
  }
}
void PopHS(StackHS &HS)
{
  NodeHS *p;
  if (isEmptyHS(HS) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    HocSinh tg;
    tg = HS.top->infor;
    HS.top = HS.top->next;
  }
}
NodeHS *TopHS(StackHS &HS)
{
  NodeHS *p;
  if (isEmptyHS(HS) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    p = HS.top;
  }
}
void inputHS(HocSinh &hs)
{
  cout << "\nNhap ma hoc sinh : ";
  cin >> hs.maHS;
  cin.ignore();
  cout << "\nNhap ho ten hoc sinh:";
  gets(hs.hoten);
  cout << "\nNhap lop: ";
  gets(hs.lop);
  cout << "\nNhap ngay sinh: ";
  gets(hs.ngaySinh);
  cout << "\nNhap gioi tinh: ";
  gets(hs.gtHS);
  cout << "\nNhap dia chi: ";
  gets(hs.diaChi);
  cout << "\n";
}
void outputHS(HocSinh &hs)
{
  cout << "\n"
       << setw(20) << hs.maHS
       << setw(15) << hs.hoten
       << setw(15) << hs.lop
       << setw(15) << hs.gtHS
       << setw(15) << hs.ngaySinh
       << setw(20) << hs.diaChi;
}
void inputDSHS(StackHS &HS)
{
  HocSinh hs;
  int n;
  cout << "\nNhap so hoc sinh: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    inputHS(hs);
    NodeHS *p = getNodeHS(hs);
    PushHS(HS, p);
  }
}
void outputDSHS(StackHS HS)
{
  NodeHS *p;
  p = HS.top;
  cout << "\nDANH SACH HOC SINH\n";
  cout << endl
       << setw(15) << "Ma hoc sinh"
       << setw(20) << "Ho ten"
       << setw(15) << "Lop"
       << setw(15) << "Ngay sinh"
       << setw(15) << "Gioi tinh"
       << setw(15) << "Dia chi";
  cout << endl;
  for (p = HS.top; p != NULL; p = p->next)
  {
    outputHS(p->infor);
  }
}
void xoaHS_Ma(StackHS &HS, int macanxoa)
{
  NodeHS *p;
  cout << "\nNhap ma hoc sinh can xoa: ";
  cin >> macanxoa;
  for (p = HS.top; p != NULL; p = p->next)
  {
    if (p->infor.maHS == macanxoa)
    {
      break;
    }
  }
  if (p == NULL)
  {
    cout << "\nKhong tim thay";
    exit(1);
  }
  else
  {
    PopHS(HS);
  }
}
string convertToString(char *a, int size)
{
  int i;
  string s = " ";
  for (i = 0; i < size; i++)
  {
    s = s + a[i];
  }
  return s;
}
NodeHS *TimKiem_ten(StackHS HS, string ten)
{
  NodeHS *p;
  for (p = HS.top; p != NULL; p = p->next)
  {
    int aSize = sizeof(p->infor.hoten);
    if ((convertToString(p->infor.hoten, aSize)).find(ten) != string ::npos)
    {
      break;
    }
  }
  return p;
}
void luuFileHS(StackHS HS)
{
  FILE *f;
  NodeHS *p = new NodeHS();
  f = fopen("HocSinh.dat", "wb");
  for (p = HS.top; p != NULL; p = p->next)
  {
    fwrite(&p->infor, sizeof(HocSinh), 1, f);
  }
  fclose(f);
  cout << "\nGhi file thanh cong!";
}
void docFileHS(StackHS &HS)
{
  initHS(HS);
  FILE *f;
  HocSinh hs;
  f = fopen("HocSinh.dat", "rb");
  while (fread(&hs, sizeof(HocSinh), 1, f))
  {
    PushHS(HS, getNodeHS(hs));
    fclose(f);
  }
  cout << "\nDoc File thanh cong!";
}
void DSearch_MaHS(StackHS HS, int n)
{
  NodeHS *p;
  cout << "\nNhap ma hoc sinh can tim: ";
  cin >> n;
  for (p = HS.top; p != NULL; p = p->next)
  {
    if (p->infor.maHS == n)
    {
      break;
    }
  }
  if (p == NULL)
  {
    cout << "\nKhong tim thay ma";
  }
  else
  {
    cout << "\nTim thay hoc sinh co ma " << n << endl;
    outputHS(p->infor);
  }
}
void addHS(StackHS &HS)
{
  NodeHS *p;
  HocSinh hs;
  inputHS(hs);
  p = getNodeHS(hs);
  PushHS(HS, p);
}
// HocSinh - End
// Mon Hoc -Begin
struct MonHoc
{
  char maMon[20], tenMon[50];
  int diemMieng, diemKtra, diemHki;
  float tbMon;
};
struct NodeMH
{
  MonHoc infor;
  struct NodeMH *next;
};
struct StackMH
{
  NodeMH *top;
};
void initMH(StackMH &MH)
{
  MH.top = NULL;
}
NodeMH *getNodeMH(MonHoc mh)
{
  NodeMH *p = new NodeMH;
  if (p == NULL)
  {
    cout << "\nKhong du bo nho";
    return 0;
  }
  p->infor = mh;
  p->next = NULL;
  return p;
}
int isEmptyMH(StackMH MH)
{
  if (MH.top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void PushMH(StackMH &MH, NodeMH *p)
{
  if (MH.top == NULL)
  {
    MH.top = p;
  }
  else
  {
    p->next = MH.top;
    MH.top = p;
  }
}
void PopMH(StackMH &MH)
{
  NodeMH *p;
  if (isEmptyMH(MH) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    MonHoc tg;
    tg = MH.top->infor;
    MH.top = MH.top->next;
  }
}
NodeMH *TopMH(StackMH &MH)
{
  NodeMH *p;
  if (isEmptyMH(MH) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    p = MH.top;
  }
  return p;
}
void inputMH(MonHoc &mh)
{
  cout << "\nNhap ma mon hoc: ";
  cin.ignore();
  gets(mh.maMon);
  cout << "\nNhap ten mon hoc: ";
  cin.ignore();
  gets(mh.tenMon);
  cout << "\nNhap diem mieng: ";
  cin >> mh.diemMieng;
  cout << "\nNhap diem kiem tra: ";
  cin >> mh.diemKtra;
  cout << "\nNhap diem hoc ki: ";
  cin >> mh.diemHki;
  mh.tbMon = mh.diemMieng * 0.1 + mh.diemKtra * 0.2 + mh.diemHki * 0.7;
}
void outputMH(MonHoc &mh)
{
  cout << "\n"
       << setw(20) << mh.maMon
       << setw(15) << mh.tenMon
       << setw(15) << mh.diemMieng
       << setw(15) << mh.diemKtra
       << setw(15) << mh.diemHki
       << setw(20) << setprecision(1) << fixed << mh.tbMon;
}
void inputDSMH(StackMH &MH)
{
  int n;
  MonHoc mh;
  NodeMH *p;
  cout << "\nNhap so mon hoc: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    inputMH(mh);
    p = getNodeMH(mh);
    PushMH(MH, p);
  }
}
void outputDSMH(StackMH MH)
{
  NodeMH *p;
  cout << setw(20) << "Ma MH";
  cout << setw(15) << "Ten MH";
  cout << setw(15) << "Diem mieng";
  cout << setw(15) << "Diem kiem tra";
  cout << setw(15) << "Diem hoc ki";
  cout << setw(20) << "TB mon";
  for (p = MH.top; p != NULL; p = p->next)
  {
    outputMH(p->infor);
  }
}
void luuFileMH(StackMH MH)
{
  FILE *f;
  NodeMH *p = new NodeMH();
  f = fopen("MonHoc.dat", "wb");
  for (p = MH.top; p != NULL; p = p->next)
  {
    fwrite(&p->infor, sizeof(MonHoc), 1, f);
    fclose(f);
  }
  cout << "\nLuu File thanh cong! ";
}
void docFileMH(StackMH MH)
{
  initMH(MH);
  FILE *f;
  MonHoc mh;
  f = fopen("MonHoc.dat", "rb");
  while (fread(&mh, sizeof(MonHoc), 1, f))
  {
    PushMH(MH, getNodeMH(mh));
    fclose(f);
  }
  cout << "\nDoc File thanh cong!";
}
void SXMH_GiamDan_Diemkra(StackMH &MH)
{
  NodeMH *p, *q;
  MonHoc mh;
  for (p = MH.top; p != NULL; p = p->next)
  {
    for (q = p->next; q != NULL; q = q->next)
    {
      if (q->infor.diemKtra > p->infor.diemKtra)
        swap(q->infor, p->infor);
    }
  }
}
void SXMH_TangDan_DiemHki(StackMH &MH)
{
  NodeMH *p, *q;
  MonHoc mh;
  for (p = MH.top; p != NULL; p = p->next)
  {
    for (q = p->next; q != NULL; q = q->next)
    {
      if (q->infor.diemHki > p->infor.diemHki)
        swap(q->infor, p->infor);
    }
  }
}
void tongDiemTBMon(StackMH MH)
{
  float tong = 0;
  float dem = 0;
  float ttb;
  NodeMH *p;
  for (p = MH.top; p != NULL; p = p->next)
  {
    tong += p->infor.tbMon;
    dem++;
  }
  ttb = tong / dem;
  cout << "\nTong trung binh cac mon: " << ttb;
  cout << "\n tong : " << tong << "dem \n"
       << dem;
}
NodeMH *Tim_TenMH(StackMH &MH, string tenmh)
{
  NodeMH *p;
  for (p = MH.top; p != NULL; p = p->next)
  {
    int aSize = sizeof(p->infor.tenMon);
    if ((convertToString(p->infor.tenMon, aSize)).find(tenmh) != string ::npos)
    {
      break;
    }
  }
  return p;
}
void xoaMH_Ma(StackMH &MH)
{
  char x[20];
  cout << "\nNhap ma mon hoc can xoa: ";
  cin.ignore();
  cin.get(x, 20);
  NodeMH *p = MH.top, *q = NULL;
  while (p != NULL)
  {
    for (p = MH.top; p != NULL; p = p->next)
    {
      if (strcmp(p->infor.maMon, x) == 0)
      {
        q = p;
        p = p->next;
      }
    }
    if (p == NULL)
    {
      cout << "\nKhong tim thay ma";
    }
    else if (p == MH.top)
    {
      MH.top = MH.top->next;
    }
    else
    {
      q->next = p->next;
      free(p);
    }
  }
}
void themMH(StackMH &MH)
{
  NodeMH *p;
  MonHoc mh;
  inputMH(mh);
  p = getNodeMH(mh);
  PushMH(MH, p);
}
// MonHoc - End
// Bang Diem - Begin
struct BangDiem
{
  char maHS[20], nguoiLap[100], ngayLap[100], hki[20];
  int nam, soLuongMon;
  float TBHK;
  HocSinh hs;
  MonHoc ds[30];
};
struct NodeBD
{
  BangDiem infor;
  struct NodeBD *next;
};
struct StackBD
{
  NodeBD *top;
};
void initBD(StackBD &BD)
{
  BD.top = NULL;
}
NodeBD *getNodeBD(BangDiem bd)
{
  NodeBD *p = new NodeBD();
  if (p == NULL)
  {
    cout << "\nKhong du bo nho ";
    exit(1);
  }
  p->infor = bd;
  p->next = NULL;
  return p;
}
int isEmptyBD(StackBD BD)
{
  if (BD.top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void PushBD(StackBD &BD, NodeBD *p)
{
  if (BD.top == NULL)
  {
    BD.top = p;
  }
  else
  {
    p->next = BD.top;
    BD.top = p;
  }
}
void PopBD(StackBD &BD)
{
  NodeBD *p;
  if (isEmptyBD(BD) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    BangDiem tg;
    tg = BD.top->infor;
    BD.top = BD.top->next;
  }
}
NodeBD *TopBD(StackBD &BD)
{
  NodeBD *p;
  if (isEmptyBD(BD) == 1)
  {
    cout << "\nNgan xep rong";
    exit(1);
  }
  else
  {
    p = BD.top;
  }
  return p;
}
void inputBD(BangDiem &bd)
{
  cout << "\nNhap ma hoc sinh: ";
  cin.ignore();
  gets(bd.maHS);
  cout << "\nNhap nam hoc: ";
  cin >> bd.nam;
  cin.ignore();
  cout << "\nNhap hoc ki: ";
  gets(bd.hki);
  cout << "\nNhap nguoi lap phieu: ";
  gets(bd.nguoiLap);
  cout << "\nNhap ngay lap: ";
  gets(bd.ngayLap);
  cout << endl;
  cout << "\nNhap danh sach hoc sinh";
  inputHS(bd.hs);
  cout << "\nNhap so mon hoc: ";
  cin >> bd.soLuongMon;
  for (int i = 0; i < bd.soLuongMon; i++)
  {
    inputMH(bd.ds[i]);
  }
  // Tinh tong trung binh hoc ki
  bd.TBHK = 0;
  for (int i = 0; i < bd.soLuongMon; i++)
  {
    bd.TBHK += bd.ds[i].tbMon;
  }
}
void outputBD(BangDiem bd)
{
  cout << "\n";
  cout << setw(20) << bd.maHS
       << setw(15) << bd.nam
       << setw(15) << bd.hki
       << setw(15) << bd.nguoiLap
       << setw(20) << bd.ngayLap;
  cout << endl;
  cout << "\nDanh sach mon hoc";
  cout << endl;
  cout << setw(20) << "Ma mon hoc"
       << setw(15) << "Ten mon hoc"
       << setw(15) << "Diem mieng"
       << setw(15) << "Diem kiem tra"
       << setw(15) << "Diem hoc ki"
       << setw(20) << "Trung binh mon";
  for (int i = 0; i < bd.soLuongMon; i++)
  {
    outputMH(bd.ds[i]);
  }
  cout << endl
       << "\n Tong trung binh hoc ki: " << bd.TBHK / bd.soLuongMon;
  cout < "\n";
}
void outputDSBD(StackBD BD)
{
  NodeBD *p;
  cout << setw(20) << "Ma HS";
  cout << setw(15) << "Nam";
  cout << setw(15) << "Hoc Ky";
  cout << setw(15) << "Nguoi lap";
  cout << setw(15) << "Ngay lap";
  cout << endl;
  for (p = BD.top; p != NULL; p = p->next)
  {
    outputBD(p->infor);
  }
}
void inputDSBD(StackBD &BD)
{
  int n;
  NodeBD *p;
  BangDiem bd;
  cout << "\nNhap so ban bang diem: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    inputBD(bd);
    p = getNodeBD(bd);
    PushBD(BD, p);
  }
}
void luuFileBD(StackBD BD)
{
  FILE *f;
  NodeBD *p = new NodeBD();
  f = fopen("BangDiem.dat", "wb");
  for (p = BD.top; p != NULL; p = p->next)
  {
    fwrite(&p->infor, sizeof(BangDiem), 1, f);
    fclose(f);
  }
  cout << "\nLuu file thanh cong!";
}
void docFileBD(StackBD BD)
{
  FILE *f;
  initBD(BD);
  BangDiem bd;
  f = fopen("BangDiem.dat", "rb");
  while (fread(&bd, sizeof(BangDiem), 1, f))
  {
    PushBD(BD, getNodeBD(bd));
    fclose(f);
  }
  cout << "\nDoc file thanh cong!";
}
void ThemBD(StackBD &BD)
{
  NodeBD *p;
  BangDiem bd;
  inputBD(bd);
  p = getNodeBD(bd);
  PushBD(BD, p);
}
NodeBD *TimBD_MaHS(StackBD BD, string x)
{
  NodeBD *p;
  for (p = BD.top; p != NULL; p = p->next)
  {
    int aSize = sizeof(p->infor.maHS);
    if ((convertToString(p->infor.maHS, aSize)).find(x) != string ::npos)
    {
      break;
    }
  }
  return p;
}
void HS_tbd_tangdan(StackBD &BD)
{
  NodeBD *p, *q;
  BangDiem tg;
  for (p = BD.top; p != NULL; p = p->next)
  {
    for (q = p->next; q != NULL; q = q->next)
    {
      if (q->infor.TBHK > p->infor.TBHK)
      {
        tg = p->infor;
        p->infor = q->infor;
        tg = q->infor;
      }
    }
  }
}
void HS_tbd_max(StackBD BD)
{
  float max;
  max = BD.top->infor.TBHK;
  for (NodeBD *p = BD.top; p != NULL; p = p->next)
  {
    if (max < p->infor.TBHK)
    {
      max = p->infor.TBHK;
    }
  }
  for (NodeBD *p = BD.top; p != NULL; p = p->next)
  {
    if (max == p->infor.TBHK)
    {
      outputBD(p->infor);
    }
  }
}
int main()
{
  NodeHS *hs;
  StackHS HS;
  initHS(HS);
  string ten;
  int macanxoa, n;
  int chon1, chon2;
  NodeMH *m;
  StackMH MH;
  initMH(MH);
  MonHoc mh;
  string tenmh;
  NodeBD *b;
  BangDiem bd;
  StackBD BD;
  initBD(BD);
  string x;
  while (1)
  {
  start:;
    system("CLS");
    cout << "\n______________________________________________________";
    cout << "\n========= QUAN LY KET QUA HOC TAP HOC SINH =========||";
    cout << "\n1. Quan ly Hoc sinh                                 ||";
    cout << "\n2. Quan ly Mon hoc                                  ||";
    cout << "\n3. Quan ly Bang diem                                ||";
    cout << "\n0. Thoat khoi chuong trinh                          ||";
    cout << "\n____________________________________________________||";
    cout << "\nNhap lua chon cua ban: ";
    cout << endl;
    cin >> chon1;
    switch (chon1)
    {
    case 1:
      while (true)
      {
        system("CLS");
        cout << "\n__________________________________________";
        cout << endl;
        cout << "\n=========== QUAN LY HOC SINH =============";
        cout << "\n1. Nhap danh sach Hoc sinh                ";
        cout << "\n2. Xuat danh sach Hoc sinh                ";
        cout << "\n3. Tim kiem Hoc sinh theo ten             ";
        cout << "\n4. Tim kiem Hoc sinh theo ma              ";
        cout << "\n5. Them mot Hoc sinh                      ";
        cout << "\n6. Xoa 1 hoc sinh dau danh sach           ";
        cout << "\n7. Xoa mot Hoc sinh theo ma               ";
        cout << "\n8. Luu file                               ";
        cout << "\n9. Doc file                               ";
        cout << "\n0. Ket thuc chuong trinh!                 ";
        cout << "\nNhap lua chon cua ban: ";
        cin >> chon2;
        switch (chon2)
        {
        case 1:
          cout << "\n NHAP DANH SACH HOC SINH\n";
          inputDSHS(HS);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 2:
          outputDSHS(HS);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 3:
          cout << "\nTim kiem nhan vien theo ten: ";
          cin.ignore();
          getline(cin, ten);
          hs = TimKiem_ten(HS, ten);
          if (hs == NULL)
          {
            cout << "\nKhong tim thay";
            cout << "\nAn phim bat ki de tiep tuc\n";
            system("pause");
            break;
          }
          else
          {
            outputHS(hs->infor);
            cout << "\nAn phim bat ki de tiep tuc\n";
            system("pause");
            break;
          }
        case 4:
          DSearch_MaHS(HS, n);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 5:
          addHS(HS);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 6:
          PopHS(HS);
          outputDSHS(HS);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 7:
          xoaHS_Ma(HS, macanxoa);
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 8:
          luuFileHS(HS);
          cout << endl;
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 9:
          docFileHS(HS);
          cout << "\n";
          outputDSHS(HS);
          cout << endl;
          cout << "\nAn phim bat ki de tiep tuc\n";
          system("pause");
          break;
        case 0:
          cout << "\nBan da thoat chuong trinh";
          goto start;
          break;
        }
      }
      system("pause");
      break;
    case 2:
      while (true)
      {
        system("CLS");
        cout << endl;
        cout << "\n=========== QUAN LY MON HOC ================ ";
        cout << "\n1. Nhap danh sach Mon hoc                    ";
        cout << "\n2. Xuat danh sach Mon hoc                    ";
        cout << "\n3. Tim kiem Mon hoc theo ten mon hoc         ";
        cout << "\n4. Luu file                                  ";
        cout << "\n5. Doc file                                  ";
        cout << "\n6. Tinh tong trung binh mon                  ";
        cout << "\n7. Them mot mon hoc                          ";
        cout << "\n8. Xoa mot mon hoc theo ma                   ";
        cout << "\n9.Sap xep diem kiem tra theo thu tu giam dan";
        cout << "\n10.Sap xep diem hoc ki theo thu tu tang dan  ";
        cout << "\n0. Ket thuc chuong trinh!                    ";
        cout << "\nNhap lua chon cua ban: ";
        cin >> chon2;
        switch (chon2)
        {
        case 1:
          cout << "\nNHAP DANH SACH MON HOC\n";
          inputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 2:
          cout << "\n DANH SACH MON HOC\n";
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 3:
          cout << "\nTim kiem nhan vien theo ten: ";
          cin.ignore();
          getline(cin, tenmh);
          m = Tim_TenMH(MH, tenmh);
          if (m == NULL)
          {
            cout << "\nKhong tim thay";
            cout << "\nAn phim bat ki de tiep tuc\n";
            system("pause");
            break;
          }
          else
          {
            outputMH(m->infor);
            cout << "\nAn phim bat ki de tiep tuc\n";
            system("pause");
            break;
          }
        case 4:
          luuFileMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 5:
          docFileMH(MH);
          cout << "\n";
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 6:
          tongDiemTBMon(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 7:
          themMH(MH);
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 8:
          xoaMH_Ma(MH);
          cout << "\nDanh sach sau khi xoa: ";
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 9:
          cout << "\nSap xep diem kiem tra theo thu tu giam dan";
          SXMH_GiamDan_Diemkra(MH);
          cout << endl;
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 10:
          cout << "\nSap xep diem hoc ki theo thu tu tang dan";
          SXMH_TangDan_DiemHki(MH);
          cout << endl;
          outputDSMH(MH);
          cout << "\nAn phim bat ky de tiep tuc\n";
          system("pause");
          break;
        case 0:
          cout << "\nBan da thoat chuong trinh";
          goto start;
          break;
        }
      }
      system("pause");
      break;
    case 3:
      while (true)
      {
        system("CLS");
        cout << "\n1. Nhap danh sach bang diem";
        cout << "\n2. Xuat danh sach bang diem";
        cout << "\n3. Tim kiem bang diem theo ma hoc sinh";
        cout << "\n4. Luu File";
        cout << "\n5. Doc File";
        cout << "\n6. Them mot bang diem bat ki";
        cout << "\n7. Xoa bang diem dau danh sach";
        cout << "\n8. Sap xep trung binh diem tang dan";
        cout << "\n9. Hoc sinh co trung binh diem Max";
        cout << "\n0. Thoat khoi chuong trinh";
        cout << "\nNhap lua chon cua ban: ";
        cin >> chon2;
        switch (chon2)
        {
        case 1:
          cout << "\nNHAP DANH SACH BANG DIEM ";
          inputDSBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 2:
          cout << "\nDANH SACH BANG DIEM";
          cout << endl;
          outputDSBD(BD);
          cout << "\n";
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 3:
          cout << "\nTIM KIEM BANG DIEM THEO MA";
          cout << endl;
          cin.ignore();
          getline(cin, x);
          b = TimBD_MaHS(BD, x);
          if (b == NULL)
          {
            cout << "\nKhong tim thay ma";
            cout << "\nAn phim bat ki de tiep tuc";
            system("pause");
            break;
          }
          else
          {
            outputBD(b->infor);
            cout << "\nAn phim bat ki de tiep tuc";
            system("pause");
            break;
          }
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 4:
          luuFileBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 5:
          docFileBD(BD);
          outputDSBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 6:
          cout << "\nTHEM MOT BANG DIEM ";
          cout << endl;
          ThemBD(BD);
          outputDSBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 7:
          cout << "\nXOA PHAN TU DAU DANH SACH";
          cout << endl;
          PopBD(BD);
          outputDSBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 8:
          cout << "\nSAP XEP TRUNG BINH DIEM TANG DAN";
          cout << endl;
          HS_tbd_tangdan(BD);
          outputDSBD(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 9:
          cout << "\nHOC SINH CO TONG TRUNG BINH CAO NHAT";
          cout << endl;
          HS_tbd_max(BD);
          cout << "\nAn phim bat ki de tiep tuc";
          system("pause");
          break;
        case 0:
          cout << "\nBan da chon thoat chuong trinh";
          goto start;
          break;
        }
      }
      system("pause");
      break;
    case 0:
      cout << "Ban da chon thoat chuong trinh";
      exit(0);
    }
  }
}