//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "巫峽");
	set ("long", @LONG
巫峽跨越川、鄂兩省，是三峽中最爲幽深秀麗的一段峽谷，西段的
崖壁由層次很薄的白色巖層組成，褶皺非常厲害，看起來象古代武士頭
頂的金盔，所以又叫金盔銀甲峽。東段，北岸的崖壁裂縫中放有黑色的
懸棺，因此叫鐵棺峽。如果說瞿塘峽象一道閘門，那麼巫峽簡直象江上
一條迂迴曲折的走廊。船隨山勢左一彎，右一轉，每一曲，每一折，都
向你展開一幅絕好的風景畫。這裏往西是瞿塘峽，東邊是西陵峽。南邊
有一座橋。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
                "west" : __DIR__"qutangxia",
                "east" : __DIR__"xilingxia",
                "south": __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
