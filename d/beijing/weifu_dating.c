// /beijing/weifu_dating.c
// Last modified by winder 2003.10.10

inherit ROOM;

void create()
{
	set("short", "韋府大廳");
	set("long", @LONG
這裏就是鹿鼎公府的大廳，相當的寬敞明亮，四周的牆上懸掛滿了
各朝名人的真跡。正廳中央坐着兩個老者，較老的老者身旁邊還站着一
個老婦和一個四十多歲的中年男子，那男子骨瘦如柴，不住的咳嗽。大
廳北邊是韋公爺的書房，左右兩邊分別是兩個廂房。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_shufang",
		"south" : __DIR__"weifu_zoulang2",
		"west" : __DIR__"weifu_fangw",
		"east" : __DIR__"weifu_fange",
	]));
	set("objects", ([
		__DIR__"npc/guixinshu" : 1,
		__DIR__"npc/guierniang" : 1,
		__DIR__"npc/guizhong" : 1,
		__DIR__"npc/liudahong" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

