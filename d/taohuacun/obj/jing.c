// jing.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"育兒經"NOR, ({"jing"}));
        set("unit", "張");
        set("long",HIG"
┏------------------ 早生貴子 --------------------┓
┃┌--------------------------------------------┐┃
┃│  bsave             ：保存檔案。            │┃
┃│  bteach/bjiao      ：教孩子武功。          │┃
┃│  bexercise/bdazuo  ：讓孩子打坐練內力。    │┃
┃│  bpractice/blian   ：讓孩子練習武功。      │┃
┃│  blearn/bxue       ：讓孩子向師父學習武功。│┃
┃│  bstudy/bdu        ：讓孩子讀書學武功技能。│┃
┃│  hp,score,skills   ：查看孩子狀態。        │┃
┃│  do <act>          ：讓你們的孩子幹活去。  │┃
┃│      目前do支持下列命令：                  │┃
┃│  go   get     give   hit     fight kill    │┃
┃│  wear remove  wield  unwield eat   drink   │┃
┃│  jifa enable  jiali  enforce yun   exert   │┃
┃│  bei  prepare fangqi abandon bai apprentice│┃
┃│                                            │┃
┃│                          俠客行一百恭賀    │┃
┃└--------------------------------------------┘┃
┗------------------------------------------------┛
"NOR);
        set("value", 0);
        set_weight(10);
        setup();
}
