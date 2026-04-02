// /kaifeng/fangsheng.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "放生池");
	set("long", @LONG
從三尺臺階走下就是大街了。臺階旁挖了一個小池子，邊上用白石
圍起了欄杆。北邊的池壁上『放生池』幾個字塗成了紅色。由於池的一
邊靠近街道，方便別人作出善舉，但整天見人把魚放下，卻是去總看不
見蹤影，多半是被附近的潑皮無賴晚上摸來作宵夜了。
LONG);
	set("exits", ([
		"east" : __DIR__"qianshou",
		"westdown" : __DIR__"wroad0",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
