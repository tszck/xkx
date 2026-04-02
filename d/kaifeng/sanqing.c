// /kaifeng/sanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long", @LONG
三清殿供奉的是三清神像，不過開封府內的居民大多到大相國寺去
燒香還願了，這裏的香火併不旺。神像也蓬頭垢面無人理會。西行去有
座高高的閣樓，就是玉皇閣。
LONG
	);
	set("objects", ([
		__DIR__"npc/obj/sanqingxiang" : 1,
		__DIR__"npc/xianghuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"yanqing",
		"north" : __DIR__"yuhuang1",
	]));

	setup();
	replace_program(ROOM);
}
