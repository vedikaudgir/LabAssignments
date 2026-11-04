"""Lab 7: Perceptron from scratch and sklearn comparison."""

from pathlib import Path

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.datasets import load_iris, load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.metrics import accuracy_score


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "outputs"
OUT.mkdir(exist_ok=True)


class ScratchPerceptron:

    def __init__(self, lr=0.1, max_epochs=100, shuffle=False, seed=42):
        self.lr = lr
        self.max_epochs = max_epochs
        self.shuffle = shuffle
        self.rng = np.random.default_rng(seed)

    def fit(self, X, y):
        self.w = np.zeros(X.shape[1])
        self.b = 0.0
        self.errors = []

        for _ in range(self.max_epochs):
            ix = np.arange(len(X))

            if self.shuffle:
                self.rng.shuffle(ix)

            err = 0

            for i in ix:
                if y[i] * (X[i] @ self.w + self.b) <= 0:
                    self.w += self.lr * y[i] * X[i]
                    self.b += self.lr * y[i]
                    err += 1

            self.errors.append(err)

            if err == 0:
                break

        self.epochs_ = len(self.errors)

        return self

    def predict(self, X):
        return np.where(
            np.asarray(X) @ self.w + self.b >= 0,
            1,
            -1
        )


def run(X, y, name):
    Xtr, Xte, ytr, yte = train_test_split(
        X,
        y,
        test_size=0.3,
        stratify=y,
        random_state=42
    )

    rows = []

    scalers = [
        ("raw", None),
        ("standard", StandardScaler()),
        ("minmax", MinMaxScaler())
    ]

    for label, sc in scalers:
        if sc:
            a = sc.fit_transform(Xtr)
            b = sc.transform(Xte)
        else:
            a = Xtr
            b = Xte

        m = ScratchPerceptron(0.1).fit(a, ytr)

        rows.append([
            name,
            label,
            accuracy_score(ytr, m.predict(a)),
            accuracy_score(yte, m.predict(b)),
            m.epochs_
        ])

        plt.figure(figsize=(5, 3))
        plt.plot(
            range(1, m.epochs_ + 1),
            m.errors,
            marker="o"
        )

        plt.title(f"{name}: {label}")
        plt.xlabel("epoch")
        plt.ylabel("misclassified")
        plt.tight_layout()

        plt.savefig(
            OUT / f"{name}_{label}_errors.png",
            dpi=140
        )

        plt.close()

    pd.DataFrame(
        rows,
        columns=[
            "dataset",
            "scaling",
            "train_accuracy",
            "test_accuracy",
            "epochs"
        ]
    ).to_csv(
        OUT / f"{name}_results.csv",
        index=False
    )


def main():
    d = load_iris()
    mask = d.target < 2

    X = d.data[mask]
    y = np.where(d.target[mask] == 1, 1, -1)

    run(X[:, :2], y, "iris_two_features")
    run(X, y, "iris_all_features")

    b = load_breast_cancer()

    run(
        b.data,
        np.where(b.target == 1, 1, -1),
        "breast_cancer"
    )

    Xtr, _, ytr, _ = train_test_split(
        X[:, :2],
        y,
        test_size=0.3,
        stratify=y,
        random_state=42
    )

    results = [
        [
            lr,
            ScratchPerceptron(lr).fit(Xtr, ytr).epochs_
        ]
        for lr in [0.01, 0.1, 1.0]
    ]

    pd.DataFrame(
        results,
        columns=["learning_rate", "epochs"]
    ).to_csv(
        OUT / "learning_rate_comparison.csv",
        index=False
    )


if __name__ == "__main__":
    main()
