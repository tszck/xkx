// Room: /d/taohua/entrance.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "入口");
	set("long", @LONG
這裏是高臺的頂層，往下有一道懸掛着的鐵梯，通向太極層。牆壁
上掛着一個大牌子，上書：“入陣者不得回頭，兇險自負！”筆勢兇猛，
似在驚嚇來人。旁邊有一個説明(shuoming)。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"taiji",
		"west" : __DIR__"hill2",
	]) );
	set("outdoors","taohua");
	set("item_desc", ([
		"shuoming" : "
入陣規則：
  以一月之日入兩儀。此入為初次進該層，如行陰則入陰，既入，復行陽則無妨。下同。
  以一日之時入四象。需知五靈對應方位的五行。
  以一年之月入五行。已生而未旺入，生之象，需生。行被生則迷，克則傷，被克則休。
                    已旺而未死入，衰之象，需克。行被克則迷，生則傷，被生則休。
                    已死方入，死之象，皆驚傷休，殆矣！
"
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}