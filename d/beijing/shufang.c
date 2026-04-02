#include <room.h>
inherit ROOM;

void create()
{
	set("short", "康親王書房");
	set("long", @LONG
這裏是康親王書房，房中書架上整整齊齊地堆放着很多書。不過書
上積了一些灰塵，顯然是很久沒有動過了。而書櫥裏的幾件精巧玉器卻
更顯得玲瓏剔透，光彩照人。
LONG );
	set("exits", ([
		"south" : __DIR__"neitang",
	]));
	set("objects", ([
		__DIR__"npc/kang" : 1,
	]));
	set("coor/x", -180);
	set("coor/y", 4084);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
