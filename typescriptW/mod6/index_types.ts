interface PackageStatus {
  /* index would be of type string and its value would be boolean */
  [status: string]: boolean;
  /* There is no limit to how many we can specify */
}

type Package = {
  packageStatus: PackageStatus;
  barcode: number;
  weight: number;
};

class PackageProcess {
  pack: Package;

  constructor(pack: Package) {
    this.pack = pack;
  }

  status() {
    return this.pack.packageStatus;
  }

  updateStatus(status: string, state: boolean) {
    this.pack.packageStatus[status] = state;
    return this.status();
  }
}

const pack: Package = {
  /* This converts to 
        packageStatus: { 'shipped': false, 'packed': true, 'delivered': true },
        There is no limit to how many we can specify 
    */
  packageStatus: { shipped: false, packed: true, delivered: true },
  barcode: 123456,
  weight: 28,
};
const processPack = new PackageProcess(pack);
console.log(processPack.status());
console.log(processPack.updateStatus("shipped", true));
