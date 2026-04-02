//Room: chunyangdian.c 純陽殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","純陽殿");
      set("long",@LONG
純陽殿海拔一千餘米，四面古木蒼翠，幽靜宜人。殿前有一石，叫普賢石，
據說普賢菩薩登山時曾坐在這裏休息過。在此可縱觀峨嵋諸峯，仰望金頂，懸
崖峭壁，離天咫尺。這裏西上至神水庵，東下是歸雲閣。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guiyunge",
          "westup"    : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
	set("coor/x", -6090);
	set("coor/y", -1040);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}