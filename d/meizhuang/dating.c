// /d/meizhuang/dating.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "四雅清風");
	set("long", @LONG
你已經到了梅莊的大廳門口，門內的匾額(bian)龍飛鳳舞的寫着“
四雅清風”四個大字，筆法娟秀中透着挺拔，不失為一筆好字。透過後
門，你看到裏面一塵不染，一張石桌和幾個石凳都安放得整整齊齊。廳
中懸着一幅大中堂，所繪的是一個仙人的背面，墨意淋漓，筆力雄健，
畫上題款是：“丹青生大醉後潑墨”八字，筆法森嚴，一筆筆便如長劍
的刺劃。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"bian" : "這塊匾已經很陳舊了，看起來搖搖晃晃的，似乎不大結實。\n",
	]));
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"keting",
		"south" : __DIR__"tianjing",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
	"/clone/board/meizhuang_b"->foo();
}
