// Room: /d/nanshaolin/cjlou.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "藏經閣一樓");
	set("long", @LONG
這裏就是南少林藏經閣。此處藏經之富，不下嵩山本院，天下罕有
其匹。這裏都是密密麻麻，高及頂棚的書架，書架間僅有容身一人通行
的空隙。幾排大書架中間，間隔地放着數丈長的書桌。目光及處，你看
到桌上放了幾本佛經。
LONG );
	set("exits", ([
		"out" : __DIR__"xiaoxi1",
		"up"  : __DIR__"cjlou1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dachi" : 1,
		BOOK_DIR+"fojing1" : random(2),
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
        if( !present("shou yu", me) &&
		(objectp(present("dachi dashi", environment(me)))) )
	{
		if (dir == "up" )
		{
			return notify_fail("大癡大師説道: 你未經許可，不能上二樓。\n");
		}
	}
	return ::valid_leave(me, dir);
}

