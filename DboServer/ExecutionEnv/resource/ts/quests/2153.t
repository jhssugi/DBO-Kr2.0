CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 7;
	rq = 0;
	tid = 2153;
	title = 215302;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 100;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 215309;
				ctype = 1;
				idx = 3242401;
				taid = 2;
			}
			CDboTSActRegQInfo
			{
				cont = 215308;
				gtype = 1;
				area = 215301;
				goal = 215304;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 215305;
				stype = 1;
				taid = 1;
				title = 215302;
			}
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "100;";
			type = 1;
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 215314;
			nextlnk = 254;
			rwdexp = 0;
			rwdtbl = 215301;
			rwdtype = 0;
			ltime = -1;
			prelnk = "2;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "2611107;";
			}
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 215308;
			gtype = 1;
			oklnk = 2;
			area = 215301;
			goal = 215304;
			sort = 215305;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 215302;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 215307;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 51;
			}
			CDboTSCheckClrQst
			{
				and = "2152;";
				flink = 1;
				flinknextqid = "2154;";
				not = 0;
			}
			CDboTSClickNPC
			{
				npcidx = "3242401;";
			}
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "0;1;252;";
			type = 0;
		}
	}
}

