// Room: /d/nanshaolin/qfdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "千佛殿");
	set("long", @LONG
這是千佛殿。大殿入口是硃紅格扇，七寶玲瓏。內裏供奉的西天諸
佛，計有八菩薩，四金剛，五百阿羅，三千揭諦，十一大曜，十八伽藍，
以及衆優婆塞，優婆夷等。直看得你眼花繚亂。佛像後邊有道小木門直
通後山。
LONG );
	set("exits", ([
		"south" : __DIR__"kchang",
		"north" : __DIR__"shanroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

