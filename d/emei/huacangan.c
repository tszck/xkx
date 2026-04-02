//Room: huacangan.c 華藏庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","華藏庵");
      set("long",@LONG
華藏庵是金頂的主要建築，規模宏大，中祀普賢菩薩，旁列萬佛。
　　華藏庵後邊是睹光臺，旁邊是臥雲庵。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "north"      : __DIR__"jinding",
          "northwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"duguangtai",
          "enter"      : __DIR__"hcazhengdian",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}