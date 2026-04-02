// Room: /yangzhou/hongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","虹橋");
	set("long",@LONG
虹橋是一座木製拱橋，圍以紅欄，因而初名「紅橋」，後因橫臥在
草河上，如同臥虹于波，才改「紅」爲「虹」。河的兩岸遍植碧桃、楊
柳，每逢春暖花開之際，夭桃逞豔，柳浪聞鶯，乃是揚州春日遊人最銷
魂的處所。古時四季均有修禊節，春禊正值陽曆三月三，春暖花開，爲
羣相聚樂的遊春賞景的節日。循晉王王羲之邀友引曲水以流觴，衆賓吟
詩之風，此後這一節日深受文人雅士青睞，成爲詩人聚會的盛大節日。
乾隆年間兩淮鹽運使盧雅雨效法前賢，作詩廣爲徵和，文人雅士，布衣
平民依韻作和的有數千人。鄭板橋，紀曉嵐，袁枚都在其中。乾隆遊此，
曾和乞丐對詩，傳爲美談。登虹橋還可遠眺秀麗湖色，招引遊人，步入
勝境。 
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"north" : "/d/shouxihu/changdi1",
		"east"  : __DIR__"beimendajie",
		"west"  : __DIR__"caohebeijie",
	]));
	set("objects", ([
		"/d/wuxi/npc/lady2" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
