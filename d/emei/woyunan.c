//Room: woyunan.c 臥雲庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","臥雲庵");
      set("long",@LONG
臥雲庵旁邊有個井絡泉，據說以前曾因飲水人多而乾涸，衆尼爲之誦經，
於是泉水復出。出了臥雲庵便是睹光臺，旁邊是華藏庵。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xuan" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "out"        : __DIR__"dgtsheshenya",
          "northeast"  : __DIR__"jinding", 
          "southeast"  : __DIR__"huacangan", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6230);
	set("coor/y", -1150);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}