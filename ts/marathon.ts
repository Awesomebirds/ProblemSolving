{
  const solution = (participant: string[], completion: string[]): string => {
    const partObj = {};
    participant.forEach((name) => {
      partObj[name] ? partObj[name]++ : (partObj[name] = 1);
    });

    completion.forEach((name) => {
      partObj[name] === 1 ? delete partObj[name] : partObj[name]--;
    });
    return Object.keys(partObj)[0];
  };
}
