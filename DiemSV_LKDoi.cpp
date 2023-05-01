#include <string.h>
#include <bits/stdc++.h>
using namespace std;
// I.Đối tượng học sinh
struct HS
{
  int MaHS;
  char TenHS[30], Lop[30], Ngaysinh[30], Sex[15], Diachi[30];
};
struct NodeHS
{
  HS info;
  NodeHS *Next;
  NodeHS *Prev;
};
struct ListHS
{
  NodeHS *Head;
  NodeHS *Tail;
};
NodeHS *getNodeHS(HS hs)
{
  NodeHS *p;
  p = new NodeHS;
  if (p == NULL)
  {
    cout << "Khong du bo nho";
    exit(1);
  }
  p->info = hs;
  p->Next = NULL;
  p->Prev = NULL;
  return p;
}
void initHS(ListHS &LHS)
{
  LHS.Head = NULL;
  LHS.Tail = NULL;
}
// Thêm đầu
void them_dau_HS(ListHS &LHS, NodeHS *p)
{
  if (LHS.Head == NULL)
  {
    LHS.Head = p;
    LHS.Tail = LHS.Head;
  }
  else
  {
    p->Next = LHS.Head;
    LHS.Head->Prev = p;
    LHS.Head = p;
  }
}
// Thêm cuối
void them_cuoi_HS(ListHS &LHS, NodeHS *p)
{
  if (LHS.Head == NULL)
  {
    LHS.Head = p;
    LHS.Tail = LHS.Head;
  }
  else
  {
    LHS.Tail->Next = p;
    p->Prev = LHS.Tail; // Phần tử trước phần tử p là phần tử cuối danh sách
    LHS.Tail = p;
  }
}
// Hiển thị 1 học sinh
void ht_1HS(HS hs)
{
  cout << "Ma hoc sinh: " << hs.MaHS << endl;
  cout << "Ten hoc sinh: " << hs.TenHS << endl;
  cout << "Lop : " << hs.Lop << endl;
  cout << "Ngay sinh hoc sinh: " << hs.Ngaysinh << endl;
  cout << "Gioi tinh hoc sinh: " << hs.Sex << endl;
  cout << "Dia chi sinh vien: " << hs.Diachi << endl;
}
// Xóa 1 hoc sinh ở vị trí bất kì(hủy p đứng sau q)
void xoa_HS_bk(ListHS &LHS, NodeHS *q)
{
  NodeHS *p;
  if (q != NULL)
  {
    p = q->Next;
    if (p != NULL)
    {
      if (p == LHS.Tail)
      {
        q->Next = NULL;
        LHS.Tail = q;
      }
      q->Next = p->Next;
      free(p);
    }
  }
}
// 1.Nhập danh sách hoc sinh
void input_HS(HS &hs)
{
  cout << "\nNhap ma hoc sinh : ";
  cin >> hs.MaHS;
  cin.ignore();
  cout << "\nNhap ho ten hoc sinh:";
  gets(hs.TenHS);
  cout << "\nNhap lop: ";
  gets(hs.Lop);
  cout << "\nNhap ngay sinh: ";
  gets(hs.Ngaysinh);
  cout << "\nNhap gioi tinh: ";
  gets(hs.Sex);
  cout << "\nNhap dia chi: ";
  gets(hs.Diachi);
  cout << "\n";
}
void nhap_HS(ListHS &LHS)
{
  int n, i = 0;
  NodeHS *p;
  HS hs;
  cout << "Nhap so hoc sinh: ";
  cin >> n;
  while (i < n)
  {
    cout << "Nhap hoc sinh thu " << i + 1 << endl;
    input_HS(hs);
    p = getNodeHS(hs);
    them_cuoi_HS(LHS, p);
    i++;
  }
}
// 2.Xuất hoc sinh
void output_HS(HS hs)
{
  cout << "\n"
       << setw(20) << hs.MaHS
       << setw(15) << hs.TenHS
       << setw(15) << hs.Lop
       << setw(15) << hs.Sex
       << setw(15) << hs.Ngaysinh
       << setw(20) << hs.Diachi;
}
void xuat_HS(ListHS LHS)
{
  NodeHS *p;
  p = LHS.Head;
  cout << "==========DANH SACH HOC SINH==========" << endl;
  cout << endl
       << setw(15) << "Ma hoc sinh"
       << setw(20) << "Ho ten"
       << setw(15) << "Lop"
       << setw(15) << "Ngay sinh"
       << setw(15) << "Gioi tinh"
       << setw(15) << "Dia chi";
  while (p != NULL)
  {
    output_HS(p->info);
    p = p->Next;
  }
}
// 3 Luu file hoc sinh
// Luu file
void luuHS(ListHS LHS)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\HS.txt", "wb");
  NodeHS *i = LHS.Head;
  while (i != NULL)
  {
    fwrite(&i->info, sizeof(HS), 1, f);
    i = i->Next;
  }
  fclose(f);
  cout << "\nGhi file thanh cong!\n";
}
// 4 . Doc filr hoc sinh
void docHS(ListHS &LHS)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\HS.txt", "rb");
  if (f == NULL)
  {
    cout << "\nKhong mo duoc file!\n";
  }
  else
  {
    HS hs;
    while (fread(&hs, sizeof(HS), 1, f) == 1)
      them_dau_HS(LHS, getNodeHS(hs));
  }
  fclose(f);
  cout << "\nDoc file thanh cong!" << endl;
}
// 5.Sắp xếp sinh vien theo ma
void SXMA_HS(ListHS &LHS)
{
  NodeHS *p, *q;
  HS hs;
  for (p = LHS.Head; p != NULL; p = p->Next)
  {
    for (q = p->Next; q != NULL; q = q->Next)
    {
      if (q->info.MaHS > p->info.MaHS)
        swap(q->info, p->info);
    }
  }
}
NodeHS *search(ListHS &LHS, int ma)
{
  NodeHS *p = LHS.Head;
  cout << "Nhap ma hoc sinh  can xoa:";
  cin >> ma;
  while (p != NULL)
  {
    if (ma == p->info.MaHS)
    {
      break;
    }
    p = p->Next;
  }
  return p;
}
void XoaMa_HS(ListHS &LHS)
{
  int ma;
  NodeHS *p;
  p = search(LHS, ma);
  if (p == NULL)
  {
    cout << "\n Khong co nhan vien co trong danh sach";
    exit(1);
  }
  else
  {
    if ((p == LHS.Head) && (p == LHS.Tail))
    {
      LHS.Head = NULL;
      LHS.Tail = NULL;
    }
    else if (p == LHS.Head)
      LHS.Head = p->Next;
    else if (p == LHS.Tail)
    {
      p->Prev->Next = NULL;
      LHS.Tail = p->Prev;
    }
    else
    {
      p->Prev->Next = p->Next;
      p->Next->Prev = p->Prev;
    }
    free(p);
  }
}
//.Chèn thêm HS
void chen_HS(ListHS &LHS)
{
  HS them;
  cout << "Nhap thong tin hoc sinh chen them:" << endl;
  input_HS(them);
  NodeHS *t = getNodeHS(them);
  them_cuoi_HS(LHS, t);
}
// Menu HOC SINH
void menu_HS()
{
  int chon;
  HS hs;
  ListHS LHS;
  initHS(LHS);
  do
  {
    cout << endl;
    cout << "***************************" << endl;
    cout << "1.Nhap danh sach hoc sinh" << endl;
    cout << "2.Hien danh sach vua nhap" << endl;
    cout << "3.Luu file danh sach hoc sinh" << endl;
    cout << "4.doc file danh sach hoc sinh" << endl;
    cout << "5.Sap xep danh sach theo ma hoc sinh" << endl;
    cout << "6.Xoa hoc sinh theo ma " << endl;
    cout << "0.Ket thuc chuong trinh" << endl;
    cout << "\n***************************" << endl;
    cout << "Moi ban chon chuc nang: ";
    cin >> chon;
    cout << endl;
    switch (chon)
    {
    case 1:
      nhap_HS(LHS);
      break;
    case 2:
      xuat_HS(LHS);
      break;
    case 3:
      luuHS(LHS);
      break;
    case 4:
      docHS(LHS);
      xuat_HS(LHS);
      break;
    case 5:
      SXMA_HS(LHS);
      cout << "Danh sach my pham sau sap xep" << endl;
      xuat_HS(LHS);
      break;
    case 6:
      XoaMa_HS(LHS);
      cout << "Danh sach sau khi xoa" << endl;
      xuat_HS(LHS);
      break;
    case 0:
      cout << "ban da thoat khoi chuong trinh" << endl;
      break;
    default:
      cout << "chuc nang ban vua nhap khong co moi ban nhap lai" << endl;
      break;
    }
  }
  while (chon != 0);
}
// I.Đối tượng Môn học
struct MH
{
  int MaMH;
  char TenMH[30];
  float dmieng, dktra, dhocki, tbmon;
};
struct NodeMH
{
  MH info;
  NodeMH *Next;
  NodeMH *Prev;
};
struct ListMH
{
  NodeMH *Head;
  NodeMH *Tail;
};
NodeMH *getNodeMH(MH mh)
{
  NodeMH *p;
  p = new NodeMH;
  if (p == NULL)
  {
    cout << "Khong du bo nho";
    exit(1);
  }
  p->info = mh;
  p->Next = NULL;
  p->Prev = NULL;
  return p;
}
void initMH(ListMH &LMH)
{
  LMH.Head = NULL;
  LMH.Tail = NULL;
}
// Thêm đầu
void them_dau_MH(ListMH &LMH, NodeMH *p)
{
  if (LMH.Head == NULL)
  {
    LMH.Head = p;
    LMH.Tail = LMH.Head;
  }
  else
  {
    p->Next = LMH.Head;
    LMH.Head->Prev = p;
    LMH.Head = p;
  }
}
// Thêm cuối
void them_cuoi_MH(ListMH &LMH, NodeMH *p)
{
  if (LMH.Head == NULL)
  {
    LMH.Head = p;
    LMH.Tail = LMH.Head;
  }
  else
  {
    LMH.Tail->Next = p;
    p->Prev = LMH.Tail; // Phần tử trước phần tử p là phần tử cuối danh sách
    LMH.Tail = p;
  }
}
// Hiển thị 1 mon hoc
void ht_1MH(MH mh)
{
  cout << "Ma mon hoc: " << mh.MaMH << endl;
  cout << "Ten mon hoc: " << mh.TenMH << endl;
  cout << "Diem mieng : " << mh.dmieng << endl;
  cout << "diem kiem tra: " << mh.dktra << endl;
  cout << "diem hoc ki: " << mh.dhocki << endl;
  cout << "diem trung binh mon: " << mh.tbmon << endl;
}
// 1.Nhập danh sách môn học
void input_MH(MH &mh)
{
  cout << "\nNhap ma mon hoc: ";
  cin.ignore();
  cin >> mh.MaMH;
  cout << "\nNhap ten mon hoc: ";
  cin.ignore();
  gets(mh.TenMH);
  cout << "\nNhap diem mieng: ";
  cin >> mh.dmieng;
  cout << "\nNhap diem kiem tra: ";
  cin >> mh.dktra;
  cout << "\nNhap diem hoc ki: ";
  cin >> mh.dhocki;
  mh.tbmon = mh.dmieng * 0.1 + mh.dktra * 0.2 + mh.dhocki * 0.7;
}
void nhap_MH(ListMH &LMH)
{
  int n, i = 0;
  NodeMH *p;
  MH mh;
  cout << "Nhap so mon hoc: ";
  cin >> n;
  while (i < n)
  {
    cout << "Nhap mon hoc thu " << i + 1 << endl;
    input_MH(mh);
    p = getNodeMH(mh);
    them_cuoi_MH(LMH, p);
    i++;
  }
}
// 2.Xuất môn học
void output_MH(MH mh)
{
  cout << "\n"
       << setw(20) << mh.MaMH
       << setw(15) << mh.TenMH
       << setw(15) << mh.dmieng
       << setw(15) << mh.dktra
       << setw(15) << mh.dhocki
       << setw(20) << setprecision(1) << fixed << mh.tbmon;
}
void xuat_MH(ListMH LMH)
{
  NodeMH *p;
  p = LMH.Head;
  cout << "==========DANH SACH MON HOC==========" << endl;
  cout << setw(20) << "Ma MH";
  cout << setw(15) << "Ten MH";
  cout << setw(15) << "Diem mieng";
  cout << setw(15) << "Diem kiem tra";
  cout << setw(15) << "Diem hoc ki";
  cout << setw(20) << "TB mon";
  while (p != NULL)
  {
    output_MH(p->info);
    p = p->Next;
  }
}
// 3 Luu file mon hoc
// Luu file
void luuMH(ListMH LMH)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\MH.txt", "wb");
  NodeMH *i = LMH.Head;
  while (i != NULL)
  {
    fwrite(&i->info, sizeof(MH), 1, f);
    i = i->Next;
  }
  fclose(f);
  cout << "\nGhi file thanh cong!\n";
}
// 4 . Doc filr mon hoc
void docMH(ListMH &LMH)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\MH.txt", "rb");
  if (f == NULL)
  {
    cout << "\nKhong mo duoc file!\n";
  }
  else
  {
    MH mh;
    while (fread(&mh, sizeof(MH), 1, f) == 1)
      them_dau_MH(LMH, getNodeMH(mh));
  }
  fclose(f);
  cout << "\nDoc file thanh cong!" << endl;
}
void sortdiemktragiam(ListMH &LMH)
{
  MH M;
  MH temp;
  NodeMH *e;
  NodeMH *f;
  for (e = LMH.Head; e != LMH.Tail; e = e->Next)
  {
    for (f = e->Next; f != NULL; f = f->Next)
    {
      if (e->info.dktra < f->info.dktra)
      {
        temp = e->info;
        e->info = f->info;
        f->info = temp;
      }
    }
  }
  cout << "\n Danh sach mon sau khi sap xep diem kiem tra giam dan: ";
  xuat_MH(LMH);
}
NodeMH *search(ListMH &LMH, int ma)
{
  NodeMH *p = LMH.Head;
  cout << "Nhap ma hoc sinh  can xoa:";
  cin >> ma;
  while (p != NULL)
  {
    if (ma == p->info.MaMH)
    {
      break;
    }
    p = p->Next;
  }
  return p;
}
void XoaMa_MH(ListMH &LMH)
{
  int ma;
  NodeMH *p;
  p = search(LMH, ma);
  if (p == NULL)
  {
    cout << "\n Khong co nhan vien co trong danh sach";
    exit(1);
  }
  else
  {
    if ((p == LMH.Head) && (p == LMH.Tail))
    {
      LMH.Head = NULL;
      LMH.Tail = NULL;
    }
    else if (p == LMH.Head)
      LMH.Head = p->Next;
    else if (p == LMH.Tail)
    {
      p->Prev->Next = NULL;
      LMH.Tail = p->Prev;
    }
    else
    {
      p->Prev->Next = p->Next;
      p->Next->Prev = p->Prev;
    }
    free(p);
  }
}
// Menu MH
void menu_MH()
{
  int chon;
  MH mh;
  ListMH LMH;
  initMH(LMH);
  do
  {
    cout << endl;
    cout << "***************************" << endl;
    cout << "1.Nhap danh sach mon hoc" << endl;
    cout << "2.Hien danh sach vua nhap" << endl;
    cout << "3.Luu file danh sach mon hoc" << endl;
    cout << "4.doc file danh sach mon hoc" << endl;
    cout << "5.Sap xep danh sach theo diem kiem tra" << endl;
    cout << "6.Xoa mon hoc theo ma " << endl;
    cout << "0.Ket thuc chuong trinh" << endl;
    cout << "\n***************************" << endl;
    cout << "Moi ban chon chuc nang: ";
    cin >> chon;
    cout << endl;
    switch (chon)
    {
    case 1:
      nhap_MH(LMH);
      break;
    case 2:
      xuat_MH(LMH);
      break;
    case 3:
      luuMH(LMH);
      break;
    case 4:
      docMH(LMH);
      xuat_MH(LMH);
      break;
    case 5:
      sortdiemktragiam(LMH);
      break;
    case 6:
      XoaMa_MH(LMH);
      cout << "Danh sach hoc sinh sau khi xoa la" << endl;
      xuat_MH(LMH);
      break;
    case 0:
      cout << "ban da thoat khoi chuong trinh" << endl;
      break;
    default:
      cout << "chuc nang ban vua nhap khong co moi ban nhap lai" << endl;
      break;
    }
  }
  while (chon != 0);
}
// III.Đối tượng bảng điểm
// Đối tượng bảng điểm
struct BD
{
  char maHS[20], nguoiLap[100], ngayLap[100], hki[20];
  int nam, soLuongMon;
  float TBHK;
  HS hs;
  MH ds[30];
};
struct NodeBD
{
  BD info;
  NodeBD *Next;
  NodeBD *Prev;
};
struct ListBD
{
  NodeBD *Head;
  NodeBD *Tail;
};
NodeBD *getNodeBD(BD bd)
{
  NodeBD *p;
  p = new NodeBD;
  if (p == NULL)
  {
    cout << "Khong du bo nho";
    exit(1);
  }
  p->info = bd;
  p->Next = NULL;
  p->Prev = NULL;
  return p;
}
void initBD(ListBD &LBD)
{
  LBD.Head = NULL;
  LBD.Tail = NULL;
}
// Thêm đầu
void them_dau_BD(ListBD &LBD, NodeBD *p)
{
  if (LBD.Head == NULL)
  {
    LBD.Head = p;
    LBD.Tail = LBD.Head;
  }
  else
  {
    p->Next = LBD.Head;
    LBD.Head->Prev = p;
    LBD.Head = p;
  }
}
// Thêm cuối
void them_cuoi_BD(ListBD &LBD, NodeBD *p)
{
  if (LBD.Head == NULL)
  {
    LBD.Head = p;
    LBD.Tail = LBD.Head;
  }
  else
  {
    LBD.Tail->Next = p;
    p->Prev = LBD.Tail; // Phần tử trước phần tử p là phần tử cuối danh sách
    LBD.Tail = p;
  }
}
void inputBD(BD &bd)
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
  input_HS(bd.hs);
  cout << "\nNhap so mon hoc: ";
  cin >> bd.soLuongMon;
  for (int i = 0; i < bd.soLuongMon; i++)
  {
    input_MH(bd.ds[i]);
  }
  // Tinh tong trung binh hoc ki
  bd.TBHK = 0;
  for (int i = 0; i < bd.soLuongMon; i++)
  {
    bd.TBHK += bd.ds[i].tbmon;
  }
}
void outputBD(BD bd)
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
    output_MH(bd.ds[i]);
  }
  cout << endl
       << "\n Tong trung binh hoc ki: " << bd.TBHK / bd.soLuongMon;
  // cout <"\n";
}
void outputDSBD(ListBD &LBD)
{
  NodeBD *p;
  cout << setw(20) << "Ma HS";
  cout << setw(15) << "Nam";
  cout << setw(15) << "Hoc Ky";
  cout << setw(15) << "Nguoi lap";
  cout << setw(15) << "Ngay lap";
  cout << endl;
  for (p = LBD.Head; p != NULL; p = p->Next)
  {
    outputBD(p->info);
  }
}
void inputDSBD(ListBD &LBD)
{
  int n;
  NodeBD *p;
  BD bd;
  cout << "\nNhap so ban bang diem: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    inputBD(bd);
    p = getNodeBD(bd);
    them_cuoi_BD(LBD, p);
  }
}
// Hiển thị 1 mon hoc
void ht_1BD(BD bd)
{
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
    output_MH(bd.ds[i]);
  }
  cout << endl
       << "\n Tong trung binh hoc ki: " << bd.TBHK / bd.soLuongMon;
  // cout <"\n";
}
// tim kiem theo ma
void tim_maBD(ListBD &LBD)
{
  char ma[10];
  int d = 0;
  NodeBD *p, *gan;
  p = LBD.Head;
  cout << "Nhap ma hoc sinh can tim: ";
  cin >> ma;
  while (p != NULL)
  {
    if (strcmp(ma, p->info.maHS) == 0)
    {
      gan = p;
      d++;
    }
    p = p->Next;
  }
  if (d == 0)
    cout << "Khong co ma hoc sinh vua nhap" << endl;
  else
  {
    cout << "Thong tin hoc sinh can tim:" << endl;
    ht_1BD(gan->info);
  }
}
// Luu file
void luuBD(ListBD LBD)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\BD.doc", "wb");
  NodeBD *i = LBD.Head;
  while (i != NULL)
  {
    fwrite(&i->info, sizeof(BD), 1, f);
    i = i->Next;
  }
  fclose(f);
  cout << "\nGhi file thanh cong!\n";
}
// 4 . Doc filr mon hoc
void docBD(ListBD &LBD)
{
  FILE *f;
  f = fopen("C:\\Users\\Admin\\Desktop\\BD.doc", "rb");
  if (f == NULL)
  {
    cout << "\nKhong mo duoc file!\n";
  }
  else
  {
    BD bd;
    while (fread(&bd, sizeof(BD), 1, f) == 1)
      them_dau_BD(LBD, getNodeBD(bd));
  }
  fclose(f);
  cout << "\nDoc file thanh cong!" << endl;
}
// 7.Chèn thêm BD
void chen_BD(ListBD &LBD)
{
  BD them;
  cout << "Nhap thong tin banh diem chen them:" << endl;
  inputBD(them);
  NodeBD *t = getNodeBD(them);
  them_cuoi_BD(LBD, t);
}
// săp xep trung binh diem tang dan
void sx_BD(ListBD &LBD)
{
  NodeBD *p, *q;
  p = LBD.Head;
  BD tg;
  while (p != NULL)
  {
    q = p->Next;
    while (q != NULL)
    {
      if ((p->info.TBHK, q->info.TBHK) == 1)
      {
        tg = p->info;
        p->info = q->info;
        q->info = tg;
      }
      q = q->Next;
    }
    p = p->Next;
  }
}
// Hoc sinh co diem trung binh cao nhat
void HS_tbd_max(ListBD &LBD)
{
  float max;
  max = LBD.Head->info.TBHK;
  for (NodeBD *p = LBD.Head; p != NULL; p = p->Next)
  {
    if (max < p->info.TBHK)
    {
      max = p->info.TBHK;
    }
  }
  for (NodeBD *p = LBD.Head; p != NULL; p = p->Next)
  {
    if (max == p->info.TBHK)
    {
      outputBD(p->info);
    }
  }
}
void xoaTail(ListBD &LBD)
{
  NodeBD *p;
  if (LBD.Tail != NULL)
  {
    p = LBD.Tail;
    LBD.Tail = LBD.Tail->Prev;
    LBD.Tail->Next = NULL;
    free(p);
    if (LBD.Head == NULL)
    {
      LBD.Tail = NULL;
    }
  }
  outputDSBD(LBD);
  ;
}
void menu_BD()
{
  int chon;
  BD bd;
  ListBD LBD;
  initBD(LBD);
  do
  {
    cout << endl;
    cout << "***************************" << endl;
    cout << "1.Nhap danh sach bang diem" << endl;
    cout << "2.Hien danh sach vua nhap" << endl;
    cout << "3. Luu File" << endl;
    cout << "4. Doc File" << endl;
    cout << "5. Them mot bang diem bat ki" << endl;
    cout << "6. Sap xep trung binh diem tang dan" << endl;
    cout << "7. Hoc sinh co trung binh diem Max" << endl;
    cout << "8.Tim bang diem bang ma hs " << endl;
    cout << "9.Xoa bang diem " << endl;
    cout << "0.Ket thuc chuong trinh" << endl;
    cout << "n***************************" << endl;
    cout << "Moi ban chon chuc nang: ";
    cin >> chon;
    cout << endl;
    switch (chon)
    {
    case 1:
      cout << "\nNHAP DANH SACH BANG DIEM ";
      inputDSBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 2:
      cout << "\nDANH SACH BANG DIEM";
      cout << endl;
      outputDSBD(LBD);
      cout << "\n";
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 3:
      luuBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 4:
      docBD(LBD);
      outputDSBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 5:
      cout << "\nTHEM MOT BANG DIEM ";
      cout << endl;
      chen_BD(LBD);
      outputDSBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 6:
      cout << "\nSAP XEP TRUNG BINH DIEM TANG DAN";
      cout << endl;
      sx_BD(LBD);
      outputDSBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 7:
      cout << "\nHOC SINH CO TONG TRUNG BINH CAO NHAT";
      cout << endl;
      HS_tbd_max(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 8:
      tim_maBD(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 9:
      xoaTail(LBD);
      cout << "\nAn phim bat ki de tiep tuc";
      system("pause");
      break;
    case 0:
      cout << "ban da thoat khoi chuong trinh" << endl;
      break;
    default:
      cout << "chuc nang ban vua nhap khong co moi ban nhap lai" << endl;
      break;
    }
  }
  while (chon != 0);
}
// Menu
int main()
{
  int chon;
  do
  {
    cout << "***************************" << endl;
    cout << "1.Quan ly danh sach hoc sinh" << endl;
    cout << "2.Quan ly danh sach mon hoc" << endl;
    cout << "3.Quan ly danh sach bang diem" << endl;
    cout << "Moi ban chon chuc nang: ";
    cin >> chon;
    cout << endl;
    switch (chon)
    {
    case 1:
      menu_HS();
      break;
    case 2:
      menu_MH();
      break;
    case 3:
      menu_BD();
      break;
    case 0:
      cout << "ban da thoat khoi chuong trinh" << endl;
      break;
    default:
      cout << "chuc nang ban vua nhap khong co moi ban nhap lai" << endl;
      break;
    }
  }
  while (chon != 0);
}