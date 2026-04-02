// Room: /d/city/shuyuan1.c
// Last Modified by winder on July. 20 2000
inherit ROOM;

void create()
{
	set("short", "至止堂");
	set("long", @LONG
這裏是書院的講堂，窗明幾淨，一塵不染。堂屋正中懸一幅青松圖，
墨沉淋漓，未同凡響。兩邊掛一幅對聯(lian)。西壁貼一孔子像，下一
紅木方桌，左右各一紅木雕花太師椅。一位莊重嚴肅的老者坐在太師椅
上講學，那就是當今大儒朱先生了。在他的兩側坐滿了求學的學生。一
張古意盎然的書案放在朱先生的前面，案上擺着幾本翻開了的線裝書籍。
講堂內多歷代楹聯石刻，足見書院歷史的悠久。值得一提的是嵌在講堂
前左壁的學規(xuegui)。書院老夫子剛奉了聖旨頒發學位，就在門口樹
着書院新立的學位公告板(board)。樓上是飛雪堂，也是書院的書庫。
LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"lian": @LONG

               花      讀 
               鳥      書
               怡      養
               情      性
LONG,
		"xuegui": "
		日講經書三起，日看綱目數頁。
		通曉時務物理，參讀古文詩賦。
		讀書必須過筆，會課按時蚤完。
		夜讀仍戒晏起，疑誤定要力爭。

	求學需繳學費十兩。\n",
		"board": "
       本書院奉聖上恩旨自即日起封授學位：
  0       文盲
 10       童生
 20       秀才
 30       舉人
 40       解元
 50       貢士
 60       會元
 70       進士
 80       探花
 90       榜眼
100       狀元
120       翰林院士
140       翰林碩士
160       翰林博士
180       翰林院編修
200       庶吉士
220       學士
240       內閣大學士
260       內閣首輔
280       文學大宗師
300       聖人\n" 
	]));
	set("exits", ([ /* sizeof() == 2 */
		"up"        : __DIR__"shuyuan2",
		"southdown" : __DIR__"shuyuan",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhu" : 1,
	]));
//	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_steal", 1);

	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}