#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book {
  char title[100];
  unsigned int num_pages;
  float price;
} Book;

typedef struct _student {
  char name[100];
  int age;
  Book *fav_book;
} Student;

Book *create_book(const char *title,unsigned int num_pages,float price) {
  Book *book = (Book*) calloc(1,sizeof(Book));

  strcpy(book->title,title);
  book->num_pages = num_pages;
  book->price = price;

  return book;
}

Book *copy_book(const Book *book) {
  return create_book(book->title,book->num_pages,book->price);
}

void print_book(const Book *book) {
  printf("Title: %s\n",book->title);
  printf("Num Pages: %d\n",book->num_pages);
  printf("Price: R$%.2f\n",book->price);
}

Student *create_student(const char *name,int age,const Book *fav_book) {
  Student *student = calloc(1,sizeof(Student));

  strcpy(student->name,name);
  student->age = age;
  student->fav_book = copy_book(fav_book);

  return student;
}

void destroy_book(Book **book_ref) {
  free(*book_ref);
  *book_ref = NULL;
}

void destroy_student(Student **student_ref) {
  Student *student = *student_ref;
  destroy_book(&student->fav_book);
  free(*student_ref);
  *student_ref = NULL;
}

void print_student(const Student *student) {
  printf("name: %s\n",student->name);
  printf("age: %d\n",student->age);
  puts("favorite book");
  puts("----");
  print_book(student->fav_book);
} 

int main() {
  Book **vet = (Book **) calloc(3,sizeof(Book *));
  vet[0] = create_book("Human Action",789,900);
  vet[1] = create_book("Nicomachean Ethics",300,30);
  vet[2] = create_book("Confessions",300,10);

  for (int i = 0; i < 3; i++)
  {
    print_book(vet[i]);
  };

  for (int i = 0; i < 3; i++)
  {
    destroy_book(&vet[i]);
    vet[i];
  }

  free(vet);
  vet = NULL;
  return 0;
}