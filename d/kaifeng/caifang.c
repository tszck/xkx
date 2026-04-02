// /kaifeng/caifang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
這間小柴房堆滿了松柴，多是賣柴的漢子因為賣不出去而拿來換上
一餐的。也有些是窮苦人上山砍了奉獻給佛祖的，好在開封邊的野豬林
多的是松樹，所以倒也從沒缺過柴禾。
LONG);

	set("objects", ([
		__DIR__"npc/obj/chaihe1" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"east" : __DIR__"caidi3",
	]));

	setup();
	replace_program(ROOM);
}
