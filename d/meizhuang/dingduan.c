// /d/meizhuang/dingduan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "書架頂部");
	set("long", @LONG
你現在在書架的頂部，從這裏你可以看見整個密室的情況，除了幾
具白骨以外，確實沒有什麼值得你懷疑的東西，但你發現書架的頂部非
常不合適的鋪着一塊紅綢。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"mishi",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/hongchou" : 1,
	]));

	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 5);
	setup();
	replace_program(ROOM);
}
