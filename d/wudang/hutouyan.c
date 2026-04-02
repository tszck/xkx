//Room: hutouyan.c 虎頭巖
//Date: Sep 22 1997
inherit ROOM;
void create()
{
      set("short","虎頭巖");
      set("long",@LONG
一塊巨大的岩石看上去好象一個虎頭正張大了血盆大口咆哮，虎身
隱藏在草木叢中。
LONG);
      set("objects", ([
          __DIR__"npc/laohu" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"wulaofeng",
          "southup"  : __DIR__"chaotiangong",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
	set("coor/x", -2030);
	set("coor/y", -980);
	set("coor/z", 140);
	setup();
      replace_program(ROOM);
}
