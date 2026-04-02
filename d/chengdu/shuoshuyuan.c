// Room: /d/chengdu/shuoshuyuan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "説書院");
	set("long", @LONG
這個書館是由全國著名的藝人張寶林坐館，自然生意興隆。張寶林
一共收了三個弟子。大弟子王誠已深得師傅真傳，大部分時間都是他在
説書。二弟子林文易，喫喝嫖賭無所不為，已被逐出師門。小弟子沈金
音，聲音如玉珠落盤委婉動聽，被譽為“百靈鳥”。
LONG	);
	set("exits", ([
		"east" : __DIR__"shuchang",
	]));
	set("objects", ([
		__DIR__"npc/wangcheng" : 1,
		__DIR__"npc/shenjinyin" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

