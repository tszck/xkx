//Room: guiyunge.c 歸雲閣
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","歸雲閣");
      set("long",@LONG
歸雲閣，原是唐代福昌達道禪師的道場。宋代紹興年間，僧人士性又率眾
重建。歸雲閣左有玉女峯，西上可抵純陽殿，東下是觀音堂。
LONG);
      set("objects", ([
           __DIR__"npc/boydizi" : 1,
           __DIR__"npc/girldizi" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guanyintang",
          "westup"    : __DIR__"chunyangdian",
          "southup"   : __DIR__"yunufeng",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6080);
	set("coor/y", -1040);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}