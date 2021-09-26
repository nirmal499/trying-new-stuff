
public class BloodPressureCheck {

    public static void main(String[] args) {

        if (args.length == 0 || args.length > 2) {
            System.err.println("Invalid INPUTS!!!");
        } else {
            var systolicBP = Integer.parseInt(args[0]);
            var diastolicBP = Integer.parseInt(args[1]);
            String systolicBPmsg = null;
            String diastolicBPmsg = null;

            // For systolicBP
            if (systolicBP <= 90) {
                systolicBPmsg = "Low";
            } else if (systolicBP > 90 && systolicBP <= 120) {
                systolicBPmsg = "Ideal";
            } else if (systolicBP > 120 && systolicBP <= 140) {
                systolicBPmsg = "Pre-High";
            } else {
                systolicBPmsg = "High";
            }

            // For diastolicBP
            if (diastolicBP <= 60) {
                diastolicBPmsg = "Low";
            } else if (diastolicBP > 60 && diastolicBP <= 80) {
                diastolicBPmsg = "Ideal";
            } else if (diastolicBP > 80 && diastolicBP <= 90) {
                diastolicBPmsg = "Pre-High";
            } else {
                diastolicBPmsg = "High";
            }

            System.out.println(systolicBPmsg + " / " + diastolicBPmsg);
        }

    }
}
