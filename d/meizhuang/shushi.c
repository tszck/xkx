// /d/meizhuang/shushi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "書室");
	set("long", @LONG
這裏是禿筆翁的書室，房中有一個大案，案上放着一個筆筒，筆筒
中插着幾管大小不同的毛筆，毛筆的質料也有所不同，有狼毫，有羊毫，
有豬鬃，有鼠須，還有一支世上很難見到的獺毫筆，案上平鋪着一張四
尺中堂大小的宣紙，一方端硯，一柄徽墨，一對白玉鎮紙，一個壽山筆
架，都顯出主人對書法的愛好。牆上掛滿了主人書寫的一幅幅條幅，中
堂，對聯。 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/weng" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3490);
	set("coor/y", -1380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
