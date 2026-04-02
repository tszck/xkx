// Room: /city/chaguan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "富春茶社");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神為之一爽。茶樓西邊
面河圍以朱欄，擺有數張茶几，上置盆景花木，數名儒生模樣的客人在
或高聲談笑，或交頭接耳或，品茶閒談。你要想打聽江湖掌故和謠言，
這裏是個好所在。南牆掛着幾幅字畫，中懸巨幅扇面。中間擺着兩張海
梅方桌，各配四張白瓷凳。此處閒靜淡雅，當是休棲之佳處。近來茶樓
隔了幾個單間供茶客們閒聊用，邊上掛着一塊牌子。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"qionghuajie",
		"west"  : __DIR__"shilijie1",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}