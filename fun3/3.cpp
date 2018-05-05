// How many way can we init an int to 0?

// static from answer
int i1 = 0;
static int i2 = 0;

int main(){
   int i3; // safe?
   int i4 = 0;
   int i5(0);
   int i6{0};
   
   // from Answer
   int i7{};
   int i8 = int();
   int i9 = {0};
   int i10 = {};
   // there's more...
}
