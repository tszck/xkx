//Room: fsanzhaitang.c 福壽庵齋堂
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","福壽庵齋堂");
      set("long",@LONG
這裏便是峨嵋福壽庵的齋堂。福壽庵本不大，但由於經常接待其他庵的弟子，
齋堂倒也不小。只見廳內擺滿了長長的餐桌和長凳，幾位小師太正來回忙碌着佈置
素齋。桌上擺了幾盆豆腐，花生，青菜以及素鴨等美味素食。北面有一扇門(door)。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"lingwenge",
          "northup" : __DIR__"fsaxiuxishi",
      ]));
      create_door("northup", "門", "southdown", DOOR_CLOSED);
      set("no_clean_up", 0);
	set("coor/x", -6110);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}