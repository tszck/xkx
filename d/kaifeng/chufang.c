// /kaifeng/chufang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "素齋廳");
	set("long", @LONG
這是寺廟中的大小僧人用餐的地方，當然方丈的素齋是專門有人送
過去的，平時相國寺的僧人聽鍾喫飯，等他們喫完了也經常把剩下的素
齋舍給窮人喫。逢塑望，十五也經常作些齋席請大施主，高官富貴們品
嘗，所以素齋廚的僧人是最忙的。
LONG
	);
	set("exits", ([
		"north" : __DIR__"chufang2",
		"west" : __DIR__"zhongyuan",
	]));
	set("objects", ([
		__DIR__"npc/liucaizhu" : 1,
		__DIR__"npc/kong" : 1,
	]));

	setup();
	replace_program(ROOM);
}
