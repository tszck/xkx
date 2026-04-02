// Room: /d/heimuya/house1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","內室");
	set("long",@LONG
這是一個精雅的小舍，一進門便可聞到一陣濃冽的花香。房中掛着
一幅五女向鳳圖，圖中繪着五個宮裝美女，美目盼兮，豔麗脫俗。屋裏
還有一張茶几，幾張椅子，椅子上鋪着繡花錦墊，西面有一扇洞形門通
向後廳。
LONG );

	set("exits",([
		"west"  : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
