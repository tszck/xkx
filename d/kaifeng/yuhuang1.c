// /kaifeng/yuhuang1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "玉皇閣");
	set("long", @LONG
玉皇閣高十三米坐北朝南，採用仿木結構均用磚砌成。外觀下閣上
亭。下圓下方，造型奇特，是一座集蒙古包與閣樓巧妙結合，具有元代
風格的建築。閣內供有真武銅像一尊。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"up"    : __DIR__"yuhuang2",
		"south" : __DIR__"sanqing",
	]));

	setup();
	replace_program(ROOM);
}
