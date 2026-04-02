// Room: /d/taohua/hill2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

string look_bei();
int do_study(string arg);

void create()
{
	set("short", "山頂");
	set("long", @LONG
這裏是山頂，很意外地，你發現東邊有一座高臺。一道石樑凌空而
架，連接着這裏和那邊的入口。幾步之外立着一座石碑(shibei)。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"hill1",
		"east" : __DIR__"entrance",
	]) );
	set("item_desc", ([
		"shibei" : (: look_bei :),
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("coor/x", 8510);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}

string look_bei()
{
	write("石碑上刻着：\n");
	write("    一日之四象：當午之時，日耀當空，光浴山河，陽氣之極盛，是爲太陽。\n");
	write("                當酉之時，日漸西山，羣星顯現，陽衰而陰盛，是爲少陽。\n");
	write("                當子之時，玉兔東昇，繁星閃動，陰氣之極盛，是爲太陰。\n");
	write("                當卯之時，旭日初現，羣星無光，陽盛而陰衰，是爲少陰。\n");
	write("    一月之陰陽：自初一而至十五，月形趨圓，漸陰之象，月圓則陰氣最盛。\n");
	write("                十五之後，月形趨缺，漸陽之象，月缺則陰氣最衰。\n");
	write("    一年之地支：正月陽氣動，去黃泉欲上書，陰尚強也。引達於寅。\n");
	write("                二月萬物冒地而出，像開門之形。冒茆於卯。\n");
	write("                三月陽氣動，雷電振，民農時也，物皆生。振美於辰。\n");
	write("                四月陽氣已出，陰氣已茂，萬物見，成文章。巳盛於巳。\n");
	write("                五月陰氣牾逆陽，冒地面出也。咒佈於午。\n");
	write("                六月滋味也，像木重枝葉也。味暖於未。\n");
	write("                七月陰氣成體，自申東。申堅於申。\n");
	write("                八月黍成可以酹酒。留執於酉。\n");
	write("                九月陽氣微，萬物畢成，陽下入地也。畢入戌。\n");
	write("                十月微陽起接陰。該閡於亥。\n");
	write("                十一月陽氣動，萬物滋。孳萌於子。\n");
	write("                十二月萬物動用事，像手五形。紐牙於醜。\n");
	write("    五行之三合：水申生，子旺，辰死。三支皆水。\n");
	write("                火寅生，午旺，戌死。三支皆火。\n");
	write("                木亥生，卯旺，未死。三支皆木。\n");
	write("                金巳生，酉旺，醜死。三支皆金。\n");
	write("                土午生，戌旺，寅死。三支皆土。\n");
	return "";
}

int do_study(string arg)
{
        object me = this_player();

	if (arg != "shibei" && arg != "bei")
		return 0;

	if (me->is_busy()) {
		write("你現在正忙着呢。\n");
		return 1;
	}

	if( me->is_fighting() ) {
		write("你無法在戰鬥中專心下來研究碑上的文字！\n");
		return 1;
	}

	if (me->query("jing") < 30) {
		write("你太累了，無法集中精神來研究碑上的文字。\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) > 150) {
		write("你仔細地讀了一遍碑上的文字，發現已經太淺顯了，無法學到新的知識。\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) < 50) {
		write("你仔細地讀了一遍碑上的文字，感到無法完全理解。\n");
		return 1;
	}
	me->receive_damage("jing", 25);
	message_vision("$N仔細地注視着石碑上的文字。\n", me);
	write("你對於六壬奇門之學的精深之處有了進一步的認識。\n");
	me->improve_skill("qimen-wuxing", me->query("int") / 2 + random(me->query("int") / 2));
	return 1;
}