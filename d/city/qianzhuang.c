// Room: /d/yangzhou/qianzhuang.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "彥明錢莊");
	set("long", @LONG
彥明錢莊是江南的老字號了，從邸家第一代「邸彥明」創下這家錢
莊後傳到現在，已經有上百年的歷史了。彥明錢莊印發的銀票各家錢莊
都給兌換，天下通用，信譽極好。錢莊裏簡簡單單，就一個櫃檯，幾個
夥計和帳房先生坐在後面，不時有人在此存錢，換錢。邊上掛着個牌子
(paizi)。
LONG );
	set("exits", ([
		"east" : __DIR__"shilijie5",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     本錢莊提供以下服務：
      存錢        deposit或者cun
      取錢        withdraw或者qu
      錢幣兌換    convert或者duihuan
      查帳        check或者chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", 0);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}