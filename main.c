#include "9cc.h"

//main処理
int main(int argc, char **argv) {
  if (argc != 2)
    error("%s：引数の個数が正しくありません", argv[0]);

  // トークナイズしてパース
  user_input = argv[1];
  token = tokenize();
  Node *node = expr();

  // アセンブリの前半部分を出力
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  //抽象構文木を下る形でコード生成
  gen(node);

  //スタックトップの値をRAXにロードして関数の返値に
  printf("  pop rax\n");
  printf("  ret\n");
  return 0;
}