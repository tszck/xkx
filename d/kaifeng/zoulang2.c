// /kaifeng/zoulang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "明廊");
	set("long", @LONG
硫璃瓦鋪的一條明廊，地面的地板離開地面三尺，擦洗得很乾淨。
每隔一段的廊檻上都鏤刻了精緻的佛像。明廊至此中斷，東面過去就是
菜園，南邊的空地上也種了幾棵菜。北面是個小柴房。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"caidi1",
		"south" : __DIR__"caidi2",
		"north" : __DIR__"caifang",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
