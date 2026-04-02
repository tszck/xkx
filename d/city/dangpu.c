// Room: /city/dangpu.c
// Last Modifyed by Winder on Dec. 12 2001

#include <ansi.h>
inherit ROOM;

int do_quit();
void create()
{
	set("short", "廣陵當鋪");
	set("long", @LONG
這是一家以買賣公平著稱的當鋪，一個五尺高的櫃檯擋在你的面前，
櫃檯上擺着一個牌子 (paizi)，櫃檯後坐着唐老闆，一雙精明的眼睛上上
下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIY"
┏------------------ "HIR"公平交易"HIY" ------------------┓
┃  ┌--------------------------------------┐  ┃
┃  │                                      │  ┃
┃  │  sell    ：賣                        │  ┃
┃  │  buy     : 買                        │  ┃
┃  │  redeem  : 贖                        │  ┃
┃  │  value   : 估價                      │  ┃
┃  │  list    : 看貨                      │  ┃
┃  │        list armor    看防具類貨物    │  ┃
┃  │        list weapon   看兵器類貨物    │  ┃
┃  │        list book     看書籍類貨物    │  ┃
┃  │        list medicine 看藥品類貨物    │  ┃
┃  │        list food     看食品類貨物    │  ┃
┃  │        list liquid   看飲品類貨物    │  ┃
┃  │        list fruit    看果品類貨物    │  ┃
┃  │        list other    看其他類貨物    │  ┃
┃  │                                      │  ┃
┃  └--------------------------------------┘  ┃
┗----------------------------------------------┛
"NOR,
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"shilijie2",
	]));

	set("coor/x", 0);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
